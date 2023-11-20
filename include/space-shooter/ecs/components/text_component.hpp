#pragma once

#include <space-shooter/ecs/component.hpp>

#include <SFML/Graphics/Text.hpp>

#include <filesystem>

namespace space_shooter::ecs {

struct TextComponent : Component {
        
  sf::Text text;

  TextComponent() = default;
  TextComponent(const std::string content, int fontSize, sf::Color color) : text{sf::Text(content, sf::Font(), fontSize)} {
      text.setColor(color);
  }
};

} // namespace space_shooter::ecs