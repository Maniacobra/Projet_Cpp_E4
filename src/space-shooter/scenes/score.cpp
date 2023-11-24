#include <space-shooter/scenes/menu.hpp>

#include <space-shooter/ecs/ecs.hpp>

namespace space_shooter {

void initScore(space_shooter::ecs::Manager& manager, bool win) {

	auto score = manager.getFromEntity<ecs::ScoreEntity>(
		[](ecs::ScoreEntity& scoreEnt) {
			scoreEnt.kill();
			return scoreEnt.getScore();
		}
	);

	// Remove previous entities

	manager.sendToEntity<ecs::AudioPlayerEntity>( // Remove sound from previous scene
		[](ecs::AudioPlayerEntity& scoreEnt) { scoreEnt.kill(); }
	);
	manager.sendToEntity<ecs::TimerEntity>( // Remove text from previous scene
		[](ecs::TimerEntity& scoreEnt) { scoreEnt.kill(); }
	);

	float centerX = manager.gameState().width / 2.f;
	float centerY = manager.gameState().height / 2.f;

	manager.registerEntity<ecs::TextEntity>(centerX, centerY - 50, win ? "You win" : "Game Over", 80, sf::Color::White);
	manager.registerEntity<ecs::TextEntity>(centerX, centerY + 30, "Press Escape to return to main menu", 30, sf::Color::Yellow);
	manager.registerEntity<ecs::TextEntity>(centerX, centerY + 100, "Score : " + std::to_string(*score), 40, sf::Color::White);
	manager.registerEntity<ecs::WaitKeyEntity>(ecs::KeySceneComponent::KeyEnum::Escape, GameState::Scene::Menu);

	manager.registerSystem<ecs::InputSystem>();
	manager.registerSystem<ecs::TextSystem>();
	manager.registerSystem<ecs::WaitKeySystem>();
}

}