#pragma once
#include <space-shooter/ecs/component.hpp>


namespace space_shooter::ecs {
	enum class EntityTag {
		None,
		Player,
		Enemy,
		PlayerMissile,
		EnemyMissile,
		EnemySpawner
	};
	struct TagComponent : Component {
		EntityTag type;
		TagComponent(EntityTag type) { this->type = type; };
	};
}