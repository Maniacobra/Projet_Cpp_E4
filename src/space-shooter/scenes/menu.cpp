#include <space-shooter/scenes/menu.hpp>

#include <space-shooter/ecs/ecs.hpp>

#include <iostream>

namespace space_shooter {

	void initMenu(space_shooter::ecs::Manager& manager) {
		std::cout << "Menu (press E to start)" << std::endl;
		manager.registerSystem<ecs::WaitKeySystem>(sf::Keyboard::E, GameState::Scene::Level);
	}
}