#include <space-shooter/scenes/level.hpp>

#include <space-shooter/ecs/ecs.hpp>

#include <iostream>

namespace space_shooter {

	void initLevel(ecs::Manager &manager, bool resume) {
  
		std::cout << "Init level." << std::endl;

		if (!resume) {
			static const std::filesystem::path& player_path = manager.gameState().config.path_to_textures / "player.png";
			static const std::filesystem::path& bg_path = manager.gameState().config.path_to_textures / "test.png";
			
			manager.registerEntity<ecs::BackgroundEntity>(bg_path, (int)manager.gameState().width, (int)manager.gameState().height);

			manager.registerEntity<ecs::PlayerShipEntity>(sf::Vector2f(
				manager.gameState().width / 2 - 50, manager.gameState().height - 200),
				100, 100, player_path, 500.f, 100);

			manager.registerEntity<ecs::EnemySpawnerEntity>(5000);
			manager.registerEntity<ecs::TimerEntity>(60000);
		}
		manager.registerEntity<ecs::WaitKeyEntity>(ecs::KeySceneComponent::KeyEnum::Escape, GameState::Scene::Pause, true);

		//Note:Registration order is the same as rendering order
		manager.registerSystem<ecs::InputSystem>();
		manager.registerSystem<ecs::ControllerSystem>();
		manager.registerSystem<ecs::MovementSystem>();
		manager.registerSystem<ecs::OOBSystem>();
		manager.registerSystem<ecs::ShootingSystem>();
		manager.registerSystem<ecs::ColliderSystem>();

		manager.registerSystem<ecs::ClockSystem>();
		manager.registerSystem<ecs::RenderingSystem>();
		manager.registerSystem<ecs::ShapeSystem>();
		manager.registerSystem<ecs::HealthBarDisplaySystem>();
		manager.registerSystem<ecs::TextSystem>();
		manager.registerSystem<ecs::TimerSystem>();
		manager.registerSystem<ecs::WaitKeySystem>();

		manager.registerSystem<ecs::EnemySpawnSystem>();
		manager.registerSystem<ecs::EnemyShootingSystem>();
		manager.registerSystem<ecs::EnemyControllerSystem>();
	}
}
