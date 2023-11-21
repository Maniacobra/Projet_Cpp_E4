#pragma once

#include <space-shooter/ecs/component.hpp>
#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/types.h>

namespace space_shooter::ecs {

struct ShootingComponent : Component {

    sf::Vector2f velocity;
    int missileSize = 10;
    sf::Color missileColor;
    EntityTag missileTag = EntityTag::None;
    EntityTag targetTag = EntityTag::None;
    bool active = false;

    ShootingComponent() = default;
    ShootingComponent(sf::Vector2f velocity, int missileSize, sf::Color missileColor, EntityTag missileTag, EntityTag targetTag = EntityTag::None) :
        velocity{velocity}, missileSize{missileSize}, missileColor{missileColor}, missileTag{missileTag}, targetTag{targetTag} {}
};

} // namespace space_shooter::ecs