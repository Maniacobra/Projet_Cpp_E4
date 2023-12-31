#include <space-shooter/ecs/systems/text_system.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

TextSystem::TextSystem()
    : System(
        type_list<PositionComponent, TextComponent>{}) {}

void TextSystem::update(const sf::Time& /*delta_time*/,
    std::vector<Entity*>& entities,
    Manager& manager) {

    // Load fonts
    if (!fontsLoaded) {
        mainFont.loadFromFile((manager.gameState().config.path_to_fonts / "Square.ttf").string());
        // Only one font for now, multiple fonts could be possible
        fontsLoaded = true;
    }

    for (auto e : entities) {
        assert(hasRequiredComponents(*e));
        const auto& pos = e->get<PositionComponent>();
        auto& text = e->get<TextComponent>();

        // Update text object position and set font
        text.text.setFont(mainFont);
        // Get the bounds to calculate the center of the text, or not if cornerPos is true
        sf::FloatRect bounds = text.cornerPos ? sf::FloatRect() : text.text.getGlobalBounds();
        text.text.setPosition(pos.x - bounds.width / 2, pos.y - bounds.height / 2);

        manager.gameState().rendering_window->draw(text.text);

    }
}

} // namespace space_shooter::ecs