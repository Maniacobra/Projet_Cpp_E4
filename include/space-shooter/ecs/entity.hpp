#pragma once

#include <space-shooter/ecs/component.hpp>
#include <space-shooter/utils.hpp>

#include <cinttypes>
#include <memory>
#include <unordered_map>

namespace space_shooter::ecs {

class Entity {
public:
  Entity() = default;
  Entity(const Entity &) = default;
  Entity(Entity &&) = default;
  Entity &operator=(const Entity &) = default;
  Entity &operator=(Entity &&) = default;

  virtual ~Entity() = default;

  template <typename Cmp, typename... Args>
  [[maybe_unused]] Cmp &add(Args &&...args) {
    size_t type_ID = getComponentTypeID<Cmp>();
    components_[type_ID] = std::unique_ptr<Component>(new Cmp{
        std::forward<Args>(args)... //
    });
    return get<Cmp>();
  }

  template <typename T> T &get() {
    size_t type_ID = getComponentTypeID<T>();
    return static_cast<T &>(*components_[type_ID]);
  }

  template <typename T> bool has() const {
    size_t type_ID = getComponentTypeID<T>();
    return components_.count(type_ID) > 0;
  }

  bool hasComponentWithID(size_t typeID) const;

  bool isAlive() const;
  void kill();

private:
  bool alive_ = true;
  std::unordered_map<size_t, std::unique_ptr<Component>> components_;
};

} // namespace space_shooter::ecs