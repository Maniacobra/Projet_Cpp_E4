#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {
	//TODO::implement different types
	enum class EnemyType {
		mob_0,
		mob_1,
		boss
	};
	struct EnemyComponent : Component {
		EnemyType type	 = EnemyType::mob_0;

		EnemyComponent(EnemyType type) {this->type = type;};
	};
}