#include <space-shooter/ecs/entities/player_ship.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

namespace space_shooter::ecs {

PlayerShipEntity::PlayerShipEntity(sf::Vector2f pos,
                                   const std::filesystem::path &texture_path,
                                   sf::Vector2f velocity) {
        PositionComponent posC  = add<PositionComponent>(pos.x, pos.y);
        InputComponent&   inpC  = add<InputComponent>();
        TextureComponent& tc    = add<TextureComponent>(texture_path);
        VelocityComponent& velC = add<VelocityComponent>(velocity.x, velocity.y);
        add<SpriteComponent>((int)tc.texture.getSize().x, (int)tc.texture.getSize().y, SpriteComponent::Resize::Scale);
        //Init components other values maybe?
    }
} // namespace space_shooter::ecs
