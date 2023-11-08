#pragma once

#include <space-shooter/ecs/component.hpp>

#include <SFML/Graphics/Text.hpp>

#include <filesystem>

namespace space_shooter::ecs {

    struct TextComponent : Component {
        
        sf::Text text;

        explicit TextComponent(const std::string content, int fontSize} text(sf::Text(content, sf::Font::loadFromFile(""), fontSize)) {
        }
    };

} // namespace space_shooter::ecs