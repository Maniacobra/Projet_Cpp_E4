#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

struct ControllableComponent : Component {
		
	float speed;

	ControllableComponent() = default;
	ControllableComponent(float speed) : speed{speed} {}
};

} // namespace space_shooter::ecs