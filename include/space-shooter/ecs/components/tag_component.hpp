#pragma once
#include <space-shooter/ecs/component.hpp>


#define ASSERT_TAG(entity, tag) if (e->get<TagComponent>().type != tag) continue;
#define ASSERT_TAG_RET(entity, tag) if (e->get<TagComponent>().type != tag) return;



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