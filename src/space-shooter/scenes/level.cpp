#include <space-shooter/scenes/level.hpp>

#include <space-shooter/ecs/ecs.hpp>

// ---

#include <space-shooter/ecs/entities/player_ship.hpp>
#include <space-shooter/ecs/systems/rendering_system.hpp>
#include <iostream>

namespace space_shooter {

	void initLevel(ecs::Manager &manager) {
  
		std::cout << "Init level." << std::endl;
		//TODO: Make see make set direcltly project path to look at 
		std::filesystem::path player_path = "..\\..\\..\\assets\\textures\\player.png";
		std::filesystem::path bg_path     = "..\\..\\..\\assets\\textures\\test.png"; 

		//const std::filesystem::path& texture_path, int window_width, int window_height
		manager.registerEntity<ecs::PlayerShipEntity>(sf::Vector2f(10.f, 10.f), player_path, sf::Vector2f(1.f, 1.f));
		manager.registerEntity<ecs::BackgroundEntity>(bg_path, (int)manager.gameState().width, (int)manager.gameState().height);
		manager.registerSystem<ecs::RenderingSystem>();
		manager.registerSystem<ecs::InputSystem>();
		manager.registerSystem<ecs::MovementSystem>();
		//manager.gameState().switch_to_scene = GameState::Scene::Score;
	}
}
