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
  add<PositionComponent>(pos.x, pos.y);
  add<InputComponent>();
  add<TextureComponent>(texture_path);
  add<SpriteComponent>(50, 20, SpriteComponent::Resize::Scale);
  add<VelocityComponent>(velocity.x, velocity.y);
}

} // namespace space_shooter::ecs
