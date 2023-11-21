#include <space-shooter/ecs/entities/enemy.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>

namespace space_shooter::ecs {

    EnemyEntity::EnemyEntity(sf::Vector2f pos, int sizeX, int sizeY, EnemyType type,const std::filesystem::path& texture_path) {
        add<PositionComponent>(pos.x, pos.y);
        add<TextureComponent>(texture_path);
        add<VelocityComponent>();
        add<SpriteComponent>(sizeX, sizeY, SpriteComponent::Resize::Scale);
        add<EnemyComponent>(type);

        setTag(EntityTag::Player);
    }
} // namespace space_shooter::ecs
