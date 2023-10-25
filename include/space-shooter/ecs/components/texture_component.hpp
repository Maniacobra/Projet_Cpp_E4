#pragma once

#include <space-shooter/ecs/component.hpp>

#include <SFML/Graphics/Texture.hpp>

#include <filesystem>

namespace space_shooter::ecs {

struct TextureComponent : Component {
  std::filesystem::path texture_path;
  bool repeated = false;
  sf::Texture texture;
  bool loaded = false;

  explicit TextureComponent(const std::filesystem::path &texture_path,
                            bool repeated = false)
      : texture_path{texture_path}, repeated{repeated} {}
};

} // namespace space_shooter::ecs