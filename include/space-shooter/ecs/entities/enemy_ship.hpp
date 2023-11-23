#pragma once
#include <space-shooter/ecs/entity.hpp>
#include <filesystem>


namespace space_shooter::ecs {

    class EnemyShipEntity : public Entity {
    public:
        EnemyShipEntity(sf::Vector2f pos, int sizeX, int sizeY, const std::filesystem::path& texture_path, int health);
        EnemyShipEntity() = delete;
        using Entity::Entity;
    };

} // namespace space_shooter::ecs