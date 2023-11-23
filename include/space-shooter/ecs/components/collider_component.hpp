#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

	struct ColliderComponent : Component {
		int hit              = 0;
		int maxHitInOneFrame = 10;
		ColliderComponent() {};
	};

} // namespace space_shooter::ecs