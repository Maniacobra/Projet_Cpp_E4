#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

struct VelocityComponent : Component {
  float vx = 0.f; // no velocity = fixed
  float vy = 0.f; // no velocity = fixed

  VelocityComponent() = default;
  VelocityComponent(float vx, float vy) : vx{vx}, vy{vy} {}
};

} // namespace space_shooter::ecs