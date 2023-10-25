#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

struct PositionComponent : Component {
  float x = 0.f;
  float y = 0.f;

  PositionComponent() = default;
  PositionComponent(float x, float y) : x{x}, y{y} {}
};

} // namespace space_shooter::ecs