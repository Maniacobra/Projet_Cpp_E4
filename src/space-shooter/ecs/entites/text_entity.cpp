#include <space-shooter/ecs/entities/text_entity.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>

#include <filesystem>

namespace space_shooter::ecs {

    TextEntity::TextEntity(float x, float y, const std::string content, int fontSize, sf::Color color) {
        add<PositionComponent>(x, y);
        add<TextComponent>(content, fontSize, color);
    }

} // namespace space_shooter::ecs
