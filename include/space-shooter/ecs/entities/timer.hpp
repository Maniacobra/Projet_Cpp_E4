#pragma once

#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/types.h>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

	class TimerEntity : public Entity {
	public:
		TimerEntity(arch millis);
		TimerEntity() = delete;

		using Entity::Entity;
	};

} // namespace space_shooter::ecs
