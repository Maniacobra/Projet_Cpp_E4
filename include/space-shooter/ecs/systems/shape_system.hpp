#pragma once

#include <space-shooter/ecs/system.hpp>

#include <SFML/Graphics/Font.hpp>

#include <vector>

namespace space_shooter::ecs {

class ShapeSystem : public System {
public:
    ShapeSystem();
    void update(const sf::Time& /*delta_time*/, std::vector<Entity*>& entities,
        Manager& manager) override;
};

} // namespace space_shooter::ecs