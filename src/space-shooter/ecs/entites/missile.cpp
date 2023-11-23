#include <space-shooter/ecs/entities/missile.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>
#include <space-shooter/ecs/components/shape_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>

namespace space_shooter::ecs {

MissileEntity::MissileEntity(sf::Vector2f pos, sf::Vector2f velocity, int radius, sf::Color color, EntityTag tag) {

    add<PositionComponent>(pos.x, pos.y);
    add<SpriteComponent>(radius * 2, radius * 2, SpriteComponent::Resize::None, true);
    add<ShapeComponent>(ShapeComponent::ShapeType::Circle, (float)radius, color);
    add<VelocityComponent>(velocity.x, velocity.y);
    add<TagComponent>(tag);
}

} // namespace space_shooter::ecs
