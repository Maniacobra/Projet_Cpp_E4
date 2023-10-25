// PROJECT HEADER HERE
#include <space-shooter/ecs/ecs.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/version.hpp>

// EXTERNAL HEADERS HERE
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

// SYSTEM HEADER HERE
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <optional>
#include <string>

int main() {
  const auto game_config = space_shooter::GameConfig {
      .title = "Space Shooter",
      .window_width = 800,
      .window_height = 600,
      .assets_path = space_shooter::SPS_PATH_TO_ASSETS,
      .frame_rate = space_shooter::FrameRate::VERTICAL_SYNC
  };

  auto manager = space_shooter::ecs::Manager(game_config);

  auto *window = manager.gameState().rendering_window.get();
  auto clock = sf::Clock{};

  while (window->isOpen() && manager.gameState().running) {
    auto event = sf::Event{};
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window->close();
    }

    window->clear();

    // call update on all registered systems
    manager.update(clock.restart());

    window->display();
  }

  return 0;
}
