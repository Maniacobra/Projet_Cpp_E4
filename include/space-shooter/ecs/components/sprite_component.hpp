#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

struct SpriteComponent : Component {

	enum class OOBAction {
		None,
		RemoveInvisible,
		Restrict
	};

  enum class Resize { None, Crop, Scale };

  int width = 0;
  int height = 0;
  Resize resize = Resize::Crop;
  OOBAction oobAct; // What happens when the sprite get out of the bounds or near it

  SpriteComponent() = default;
  SpriteComponent(int width, int height, Resize resize = Resize::Crop, OOBAction oobAct = OOBAction::None)
      : width{width}, height{height}, resize{resize}, oobAct{oobAct} {}
};

} // namespace space_shooter::ecs