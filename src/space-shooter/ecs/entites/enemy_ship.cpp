
#include <space-shooter/ecs/entities/enemy_ship.hpp>
#include <space-shooter/ecs/components/all.hpp>

#include <filesystem>


namespace space_shooter::ecs {

    EnemyShipEntity::EnemyShipEntity(sf::Vector2f pos, int sizeX, int sizeY, const std::filesystem::path& texture_path, int health) {
        add<PositionComponent>(pos.x, pos.y);
        add<VelocityComponent>();
        add<ShootingComponent>(sf::Vector2f(0.f, 200.0f), 10, sf::Color::Blue, EntityTag::EnemyMissile).active = true; //Always enemy is hooting if not told otherwise
        add<ClockComponent>(random(1000, 3000));
        add<TextureComponent>(texture_path);
        add<SpriteComponent>(sizeX, sizeY, SpriteComponent::Resize::Scale);
        add<TagComponent>(EntityTag::Enemy);
        add<HealthComponent>(health);
        add<ColliderComponent>();
    }
};