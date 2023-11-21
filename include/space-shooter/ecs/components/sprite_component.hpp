#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

struct SpriteComponent : Component {
  enum class Resize { None, Crop, Scale };

  int width = 0;
  int height = 0;
  Resize resize = Resize::Crop;
  bool removeOOB;

  SpriteComponent() = default;
  SpriteComponent(int width, int height, Resize resize = Resize::Crop, bool removeOOB = false)
      : width{width}, height{height}, resize{resize}, removeOOB{removeOOB} {}
};

} // namespace space_shooter::ecs