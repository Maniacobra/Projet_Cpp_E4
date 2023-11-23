#pragma once

#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/components/position_component.hpp>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

class PlayerShipEntity : public Entity {
  PositionComponent* posCmp;
public:
  PlayerShipEntity(sf::Vector2f pos, int sizeX, int sizeY, const std::filesystem::path &texture_path, float speed, int health);
  PlayerShipEntity() = delete;
  PositionComponent* getPos();

  using Entity::Entity;
};

} // namespace space_shooter::ecs
