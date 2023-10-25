#include <space-shooter/ecs/entity.hpp>

namespace space_shooter::ecs {

bool Entity::hasComponentWithID(size_t type_ID) const {
  return components_.count(type_ID) > 0;
}

bool Entity::isAlive() const { return alive_; }

void Entity::kill() { alive_ = false; }

} // namespace space_shooter::ecs