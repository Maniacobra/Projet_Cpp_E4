#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include <filesystem>
#include <memory>
#include <string>
#include <vector>

namespace space_shooter {
enum class FrameRate { VERTICAL_SYNC, LIMIT_FPS };

inline constexpr auto FPS_LIMIT = 60;

struct Config {
  std::filesystem::path path_to_textures;
  std::filesystem::path path_to_audio;
  std::filesystem::path path_to_fonts;
};

struct GameConfig {
  std::string title;
  std::size_t window_width;
  std::size_t window_height;
  std::filesystem::path assets_path;
  space_shooter::FrameRate frame_rate;
};

struct GameState {
  enum class Scene { None, Exit, Menu, Level, Score, Pause, Resume };

  Config config;
  std::size_t width;
  std::size_t height;
  FrameRate frame_rate_type;
  std::unique_ptr<sf::RenderWindow> rendering_window;
  Scene switch_to_scene;
  bool running;
  bool keep_entities;
  bool keep_systems;
};

std::unique_ptr<GameState> initGameState(const GameConfig &game_config);

} // namespace space_shooter
