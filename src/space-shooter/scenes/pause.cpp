#include <space-shooter/scenes/menu.hpp>

#include <space-shooter/ecs/ecs.hpp>

#include <iostream>

namespace space_shooter {

	void initPause(space_shooter::ecs::Manager& manager) {

		float centerX = manager.gameState().width / 2.f;
		float centerY = manager.gameState().height / 2.f;

		std::cout << "Pause\n";

		manager.registerEntity<ecs::TextEntity>(manager.gameState().width / 2.f, manager.gameState().height / 2.f,
			"Pause", 80, sf::Color::Yellow);
		manager.registerEntity<ecs::WaitKeyEntity>(ecs::KeySceneComponent::KeyEnum::Escape, GameState::Scene::Resume, true);

		// For level
		manager.registerSystem<ecs::RenderingSystem>();
		manager.registerSystem<ecs::ShapeSystem>();
		manager.registerSystem<ecs::HealthBarDisplaySystem>();
		// For pause
		manager.registerSystem<ecs::InputSystem>();
		manager.registerSystem<ecs::TextSystem>();
		manager.registerSystem<ecs::WaitKeySystem>();
	}
}