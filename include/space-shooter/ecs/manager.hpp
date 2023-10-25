#pragma once

#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/system.hpp>

#include <functional>
#include <memory>
#include <optional>
#include <type_traits>
#include <vector>

namespace space_shooter {

struct GameState;

namespace ecs {

class Manager {
public:
  Manager(const GameConfig &game_config);

  GameState &gameState();
  const GameState &gameState() const;

  template <typename Ent, typename... Args>
  [[maybe_unused]] Ent &registerEntity(Args &&...args) {
    auto entity = std::unique_ptr<Entity>{
        new Ent{std::forward<Args>(args)...} //
    };
    entities_.push_back(std::move(entity));
    return static_cast<Ent &>(*entities_.back());
  }

  template <typename Sys, typename... Args>
  [[maybe_unused]] Sys &registerSystem(Args &&...args) {
    auto system = std::unique_ptr<System>{
        new Sys{std::forward<Args>(args)...} //
    };
    systems_.push_back(std::move(system));
    return static_cast<Sys &>(*systems_.back());
  }

  void update(const sf::Time &delta_time);

  template <class Ent> void killEntity() {
    for (auto &ent : entities_) {
      if (auto *ent_to_kill = dynamic_cast<Ent *>(&*ent);
          ent_to_kill != nullptr) {
        ent_to_kill->kill();
      }
    }
  }

  template <class Sys> void killSystem() {
    for (auto &sys : systems_) {
      if (auto *sys_to_kill = dynamic_cast<Sys *>(&*sys);
          sys_to_kill != nullptr) {
        sys_to_kill->kill();
      }
    }
  }

  template <class Sys> void disableSystem() {
    for (auto &sys : systems_) {
      if (auto *sys_to_disable = dynamic_cast<Sys *>(&*sys);
          sys_to_disable != nullptr) {
        sys_to_disable->disable();
      }
    }
  }

  template <class Sys> void enableSystem() {
    for (auto &sys : systems_) {
      if (auto *sys_to_enable = dynamic_cast<Sys *>(&*sys);
          sys_to_enable != nullptr) {
        sys_to_enable->enable();
      }
    }
  }

  template <class Ent, class Func> void sendToEntity(Func &&f) {
    for (auto &e : entities_) {
      if (auto *ent = dynamic_cast<Ent *>(&*e); ent != nullptr) {
        std::invoke(std::forward<Func>(f), *ent);
      }
    }
  }

  template <class Ent, class Func>
  [[maybe_unused]] auto getFromEntity(Func &&f)
      -> std::optional<std::invoke_result_t<Func, Ent &>> {
    for (auto &e : entities_) {
      if (auto *ent = dynamic_cast<Ent *>(&*e); ent != nullptr) {
        return std::invoke(std::forward<Func>(f), *ent);
      }
    }

    return std::nullopt;
  }

  void clearEntities();
  void clearSystems();
  void clearAll();
  void disableAllSystems();
  void enableAllSystems();

private:
  std::vector<Entity *> filterEntitiesForSystem(System *system);
  void triggerSceneChange();

private:
  std::vector<std::unique_ptr<Entity>> entities_;
  std::vector<std::unique_ptr<System>> systems_;
  std::unique_ptr<GameState> game_state_;
};

} // namespace ecs
} // namespace space_shooter