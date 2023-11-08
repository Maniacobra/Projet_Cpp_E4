#pragma once

#include <SFML/Window/Keyboard.hpp>

#include <space-shooter/ecs/ecs.hpp>
#include <space-shooter/ecs/system.hpp>
#include <space-shooter/game_state.hpp>
#include <vector>

namespace space_shooter::ecs {

	class WaitKeySystem : public System {

		sf::Keyboard::Key key;
		GameState::Scene scene;

	public:
		WaitKeySystem(sf::Keyboard::Key key, GameState::Scene scene);
		void update(const sf::Time&, std::vector<Entity*>& entities, Manager& manager) override;
	};
}