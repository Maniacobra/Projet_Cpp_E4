#include <space-shooter/ecs/entities/player_ship.hpp>

#include <space-shooter/ecs/components/controllable_component.hpp>
#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>

namespace space_shooter::ecs {

PlayerShipEntity::PlayerShipEntity(sf::Vector2f pos, int sizeX, int sizeY,
                                   const std::filesystem::path &texture_path,
                                   float speed) {
        add<PositionComponent>(pos.x, pos.y);
        add<InputComponent>();
        add<TextureComponent>(texture_path);
        add<ControllableComponent>(speed);
        add<VelocityComponent>();
        add<SpriteComponent>(sizeX, sizeY, SpriteComponent::Resize::Scale);
        setTag(EntityTag::Player);
    }
} // namespace space_shooter::ecs
