#pragma once

#include <SFML/System/Vector2.hpp>

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

struct PositionComponent : Component {
  float x = 0.f;
  float y = 0.f;

  PositionComponent() = default;
  PositionComponent(float x, float y) : x{x}, y{y} {}

  sf::Vector2f asVec() const {
	  return sf::Vector2f(x, y);
  }
};

} // namespace space_shooter::ecs