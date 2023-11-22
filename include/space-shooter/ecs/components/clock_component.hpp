#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

struct ClockComponent : Component {
	
	long t = 0.L;
	long duration;
	bool repeat = true;
	bool over = false;

	ClockComponent() = default;
	ClockComponent(long millis) : duration{millis * 1000L} {}
};

} // namespace space_shooter::ecs