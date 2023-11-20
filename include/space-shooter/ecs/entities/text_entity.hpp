#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

class TextEntity : public Entity {
public:
  TextEntity(float x, float y, const std::string content, int fontSize, sf::Color color); // x and y are the center if the text
  TextEntity() = delete;

  using Entity::Entity;
};

} // namespace space_shooter::ecs
