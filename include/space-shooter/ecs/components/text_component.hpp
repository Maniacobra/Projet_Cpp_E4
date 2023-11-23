#pragma once

#include <space-shooter/ecs/component.hpp>

#include <SFML/Graphics/Text.hpp>

#include <filesystem>

namespace space_shooter::ecs {

struct TextComponent : Component {
        
  sf::Text text;
  bool cornerPos;

  TextComponent() = default;
  TextComponent(const std::string content, int fontSize, sf::Color color, bool cornerPos = false) :
      text{sf::Text(content, sf::Font(), fontSize)}, cornerPos{cornerPos} {
      text.setColor(color);
  }
};

} // namespace space_shooter::ecs