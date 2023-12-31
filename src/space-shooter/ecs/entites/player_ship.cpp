#include <space-shooter/ecs/entities/player_ship.hpp>

#include <space-shooter/ecs/components/all.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>

namespace space_shooter::ecs {

PlayerShipEntity::PlayerShipEntity(sf::Vector2f pos, int sizeX, int sizeY,
                                   const std::filesystem::path &texture_path,
                                   float speed, int health) :
                                   posCmp(add<PositionComponent>(pos.x, pos.y)), healthCmp(add<HealthComponent>(health)) {
        add<InputComponent>();
        add<ControllableComponent>(speed);
        add<VelocityComponent>();
        add<ShootingComponent>(sf::Vector2f(0.f, -1000.f), 8, sf::Color::Red, EntityTag::PlayerMissile);
        add<ClockComponent>(200);
        add<ColliderComponent>();
        add<TextureComponent>(texture_path);
        add<SpriteComponent>(sizeX, sizeY, SpriteComponent::Resize::Scale, SpriteComponent::OOBAction::Restrict);
        add<TagComponent>(EntityTag::Player);
    }

PositionComponent& PlayerShipEntity::getPos() {
    return posCmp;
}

HealthComponent& PlayerShipEntity::getHealth() {
    return healthCmp;
}

} // namespace space_shooter::ecs
