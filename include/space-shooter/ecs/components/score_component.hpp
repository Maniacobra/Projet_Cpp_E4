#pragma once

#include <space-shooter/ecs/component.hpp>
#include <space-shooter/types.h>

namespace space_shooter::ecs {

	struct ScoreComponent : Component {

		int score;

		ScoreComponent() = default;
		ScoreComponent(int score) : score{score} {}
	};

} // namespace space_shooter::ecs