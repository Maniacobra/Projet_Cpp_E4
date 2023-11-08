#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

    class TextEntity : public Entity {
    public:
        TextEntity(sf::Vector2f pos, const string content, int fontSize);

        using Entity::Entity;
    };

} // namespace space_shooter::ecs
