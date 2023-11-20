#include <space-shooter/scenes/level.hpp>

#include <space-shooter/ecs/ecs.hpp>

// ---

#include <space-shooter/ecs/entities/player_ship.hpp>
#include <space-shooter/ecs/systems/rendering_system.hpp>
#include <iostream>

namespace space_shooter {

	void initLevel(ecs::Manager &manager) {
  
		std::cout << "Init level." << std::endl;
		static const std::filesystem::path& player_path = manager.gameState().config.path_to_textures / "player.png";
		static const std::filesystem::path& bg_path     = manager.gameState().config.path_to_textures / "test.png";
		//Note:Registration order is the same as rendering order
		manager.registerEntity<ecs::BackgroundEntity>(bg_path, (int)manager.gameState().width, (int)manager.gameState().height);
		manager.registerEntity<ecs::PlayerShipEntity>(sf::Vector2f(10., 10.f), player_path, sf::Vector2f(1000.f, 1000.f));

		manager.registerSystem<ecs::RenderingSystem>();
		manager.registerSystem<ecs::InputSystem>();
		manager.registerSystem<ecs::MovementSystem>();
		//manager.gameState().switch_to_scene = GameState::Scene::Score;
	}
}
