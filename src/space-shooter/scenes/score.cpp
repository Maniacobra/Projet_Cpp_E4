#include <space-shooter/scenes/menu.hpp>

#include <space-shooter/ecs/ecs.hpp>

namespace space_shooter {

	void initScore(space_shooter::ecs::Manager& manager) {

		float centerX = manager.gameState().width / 2.f;
		float centerY = manager.gameState().height / 2.f;

		manager.registerEntity<ecs::TextEntity>(centerX, centerY - 50, "Game Over", 80, sf::Color::White);
		manager.registerEntity<ecs::TextEntity>(centerX, centerY + 30, "Press Escape to return to main menu", 30, sf::Color::Yellow);
		manager.registerEntity<ecs::WaitKeyEntity>(ecs::KeySceneComponent::KeyEnum::Enter, GameState::Scene::Menu);

		manager.registerSystem<ecs::TextSystem>();
		manager.registerSystem<ecs::WaitKeySystem>();
	}
}