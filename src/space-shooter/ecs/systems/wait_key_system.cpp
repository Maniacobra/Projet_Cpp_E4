#include <space-shooter/ecs/systems/wait_key_system.hpp>

namespace space_shooter::ecs {

	WaitKeySystem::WaitKeySystem(sf::Keyboard::Key key, GameState::Scene scene) : System(type_list<>{}), key(key), scene(scene) {}

	void WaitKeySystem::update(const sf::Time&, std::vector<Entity*>& entities, Manager& manager) {
		if (sf::Keyboard::isKeyPressed(key))
			manager.gameState().switch_to_scene = scene;
	}
}