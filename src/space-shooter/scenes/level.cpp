#include <space-shooter/scenes/level.hpp>

#include <space-shooter/ecs/ecs.hpp>()

#include <iostream>

namespace space_shooter {

	void initLevel(ecs::Manager &manager) {
  
		std::cout << "Init level." << std::endl;
		static const std::filesystem::path& player_path = manager.gameState().config.path_to_textures / "player.png";
		static const std::filesystem::path& bg_path     = manager.gameState().config.path_to_textures / "test.png";
		//Note:Registration order is the same as rendering order
		manager.registerEntity<ecs::BackgroundEntity>(bg_path, (int)manager.gameState().width, (int)manager.gameState().height);
		manager.registerEntity<ecs::PlayerShipEntity>(sf::Vector2f(10.f, 10.f), 100, 100, player_path, 500.f, 100);
		manager.registerEntity<ecs::EnemySpawnerEntity>(5000);

		manager.registerSystem<ecs::InputSystem>();
		manager.registerSystem<ecs::ControllerSystem>();
		manager.registerSystem<ecs::ShootingSystem>();
		manager.registerSystem<ecs::MovementSystem>();
		manager.registerSystem<ecs::ClockSystem>();
		manager.registerSystem<ecs::OOBSystem>();
		manager.registerSystem<ecs::RenderingSystem>();
		manager.registerSystem<ecs::ShapeSystem>();
		manager.registerSystem<ecs::HealthBarDisplaySystem>();

		manager.registerSystem<ecs::EnemySpawnSystem>();
		manager.registerSystem<ecs::EnemyShootingSystem>();
	}
}
