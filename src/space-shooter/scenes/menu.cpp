#include <space-shooter/scenes/menu.hpp>

#include <space-shooter/ecs/ecs.hpp>

#include <iostream>

namespace space_shooter {

	void initMenu(space_shooter::ecs::Manager& manager) {
		std::cout << "Menu (press E to start)" << std::endl;

		float centerX = manager.gameState().width / 2.f;
		float centerY = manager.gameState().height / 2.f;
		
		manager.registerEntity<ecs::TextEntity>(centerX, centerY - 50, "Welcome", 80, sf::Color::White);
		manager.registerEntity<ecs::TextEntity>(centerX, centerY + 30, "Press E to start", 40, sf::Color::Yellow);
		manager.registerEntity<ecs::TextEntity>(centerX, centerY + 70, "Use keyboard arrows to move", 40, sf::Color::Yellow);
		manager.registerSystem<ecs::TextSystem>();
		manager.registerSystem<ecs::WaitKeySystem>(sf::Keyboard::E, GameState::Scene::Level);
	}
}