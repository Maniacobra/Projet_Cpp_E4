#include <space-shooter/scenes/level.hpp>

#include <space-shooter/ecs/ecs.hpp>

#include <iostream>

namespace space_shooter {

	void initLevel(ecs::Manager &manager, bool resume) {
  
		std::cout << "Init level." << std::endl;

		manager.sendToEntity<ecs::TextEntity>( // Remove text from previous scene
			[](ecs::TextEntity& scoreEnt) {
				scoreEnt.kill();
			}
		);

		if (!resume) {
			static const std::filesystem::path& player_path = manager.gameState().config.path_to_textures / "player.png";
			static const std::filesystem::path& bg_path	    = manager.gameState().config.path_to_textures / "bg.png";
			
			manager.registerEntity<ecs::BackgroundEntity>(bg_path, (int)manager.gameState().width, (int)manager.gameState().height);
			manager.registerEntity<ecs::PlayerShipEntity>(sf::Vector2f(manager.gameState().width / 2, manager.gameState().height - 100), 100, 100, player_path, 500.f, 5);
			manager.registerEntity<ecs::EnemySpawnerEntity>(1000);
			manager.registerEntity<ecs::AudioPlayerEntity>(manager.gameState().config.path_to_audio / "NightRide.wav", true);
			manager.registerEntity<ecs::TimerEntity>(120000);
			manager.registerEntity<ecs::ScoreEntity>();
		}
		manager.registerEntity<ecs::WaitKeyEntity>(ecs::KeySceneComponent::KeyEnum::Escape, GameState::Scene::Pause, true);

		//Note:Registration order is the same as rendering order
		manager.registerSystem<ecs::InputSystem>();
		manager.registerSystem<ecs::ControllerSystem>();
		manager.registerSystem<ecs::MovementSystem>();
		manager.registerSystem<ecs::OOBSystem>();
		manager.registerSystem<ecs::ShootingSystem>();
		manager.registerSystem<ecs::ColliderSystem>();
		manager.registerSystem<ecs::HealthSystem>();
		manager.registerSystem<ecs::ScoreSystem>();

		manager.registerSystem<ecs::ClockSystem>();
		manager.registerSystem<ecs::RenderingSystem>();
		manager.registerSystem<ecs::ShapeSystem>();
		manager.registerSystem<ecs::HealthBarDisplaySystem>();
		manager.registerSystem<ecs::TextSystem>();
		manager.registerSystem<ecs::TimerSystem>();
		manager.registerSystem<ecs::WaitKeySystem>();

		manager.registerSystem<ecs::EnemySpawnSystem>();
		manager.registerSystem<ecs::EnemyControllerSystem>();
		
        manager.registerSystem<ecs::AudioSystem>();
	}
}
