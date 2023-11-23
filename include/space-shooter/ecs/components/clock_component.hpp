#pragma once

#include <space-shooter/ecs/component.hpp>
#include <space-shooter/types.h>

namespace space_shooter::ecs {

struct ClockComponent : Component {
	
	arch t;
	arch duration;
	bool repeat = true;
	bool over = false;

	ClockComponent() = default;
	ClockComponent(arch millis) : duration{millis * 1000L}, t{millis * 1000L} {}
};

} // namespace space_shooter::ecs