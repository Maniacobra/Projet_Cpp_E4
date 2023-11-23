#pragma once

#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

	class MissileEntity : public Entity {
	public:
		MissileEntity(sf::Vector2f pos, sf::Vector2f velocity, int radius, sf::Color color, EntityTag tag);
		MissileEntity() = delete;

		using Entity::Entity;
	};

} // namespace space_shooter::ecs
