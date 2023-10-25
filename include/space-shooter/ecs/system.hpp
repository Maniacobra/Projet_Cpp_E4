#pragma once

#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/utils.hpp>

#include <unordered_set>
#include <vector>

namespace space_shooter::ecs {

class Manager;

template <typename... T> struct type_list {};

class System {
public:
  template <typename... RequiredComponents>
  System(type_list<RequiredComponents...>)
      : alive_{true}, enabled_{true},
        required_components_{getComponentTypeID<RequiredComponents>()...} {}

  virtual ~System() = default;

  virtual void update(const sf::Time &delta_time,
                      std::vector<Entity *> &entities, Manager &manager) = 0;

  const std::unordered_set<size_t> &getRequiredComponents() const;
  bool hasRequiredComponents(const Entity &ent) const;

  bool isAlive() const;
  void kill();
  void disable();
  void enable();
  bool isEnabled();

protected:
  bool alive_;
  bool enabled_;
  std::unordered_set<size_t> required_components_;
};

} // namespace space_shooter::ecs