#include <space-shooter/ecs/entities/missile.hpp>

#include <space-shooter/ecs/components/all.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>

namespace space_shooter::ecs {

MissileEntity::MissileEntity(sf::Vector2f pos, sf::Vector2f velocity, int radius, sf::Color color, EntityTag tag) {

    add<PositionComponent>(pos.x, pos.y);
    add<SpriteComponent>(radius * 2, radius * 2, SpriteComponent::Resize::None, SpriteComponent::OOBAction::RemoveInvisible);
    add<ShapeComponent>(ShapeComponent::ShapeType::Circle, (float)radius, color);
    add<VelocityComponent>(velocity.x, velocity.y);
    add<TagComponent>(tag);

    add<ColliderComponent>();
    add<HealthComponent>(1);
}

} // namespace space_shooter::ecs
