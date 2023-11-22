#pragma once

#include <SFML/Window/Keyboard.hpp>

#include <space-shooter/ecs/ecs.hpp>
#include <space-shooter/ecs/system.hpp>
#include <vector>


namespace space_shooter::ecs {

	class WaitKeySystem : public System {
	public:
		WaitKeySystem();
		void update(const sf::Time&, std::vector<Entity*>& entities, Manager& manager) override;
	};
}