#pragma once
#include <space-shooter/ecs/component.hpp>


#define ASSERT_TAG(entity, tag) if (e->get<TagComponent>().type != EntityTag::Enemy) continue;


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