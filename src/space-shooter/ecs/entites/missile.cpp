#include <space-shooter/ecs/entities/missile.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>
#include <space-shooter/ecs/components/shape_component.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>

namespace space_shooter::ecs {

MissileEntity::MissileEntity(sf::Vector2f pos, sf::Vector2f velocity, sf::Color color) {

    add<PositionComponent>(pos.x, pos.y);
    add<ShapeComponent>(ShapeComponent::ShapeType::Circle, 15.f, color);
    add<VelocityComponent>(velocity.x, velocity.y);
}

} // namespace space_shooter::ecs
