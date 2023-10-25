#include <space-shooter/ecs/system.hpp>

namespace space_shooter::ecs

{

const std::unordered_set<size_t> &System::getRequiredComponents() const {
  return required_components_;
}

bool System::hasRequiredComponents(const Entity &ent) const {
  for (auto &&cmpID : required_components_) {
    if (!ent.hasComponentWithID(cmpID)) {
      return false;
    }
  }

  return true;
}

bool System::isAlive() const { return alive_; }

void System::kill() { alive_ = false; }

void System::disable() { enabled_ = false; }

void System::enable() { enabled_ = true; }

bool System::isEnabled() { return enabled_; }

} // namespace space_shooter::ecs