#pragma once

#include <space-shooter/ecs/component.hpp>
#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>

namespace space_shooter::ecs {

struct ShootingComponent : Component {

    sf::Vector2f velocity;
    int missileSize = 10;
    sf::Color missileColor;
    EntityTag missileTag = EntityTag::None;
    bool targetPlayer;
    bool active = false;

    ShootingComponent() = default;
    ShootingComponent(sf::Vector2f velocity, int missileSize, sf::Color missileColor, EntityTag missileTag, bool targetPlayer = false) :
        velocity{velocity}, missileSize{missileSize}, missileColor{missileColor}, missileTag{missileTag}, targetPlayer{targetPlayer} {}
};

} // namespace space_shooter::ecs