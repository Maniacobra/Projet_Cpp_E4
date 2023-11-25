#pragma once

#include <space-shooter/ecs/system.hpp>

#include <vector>

namespace space_shooter::ecs {

    // OOB stands for "Out Of Bounds", this system checks what to do when sprites get close the border of the screen or cross past

    class OOBSystem : public System {
    public:
        OOBSystem();
        void update(const sf::Time& delta_time, std::vector<Entity*>& entities,
            Manager& manager) override;
    };

} // namespace space_shooter::ecs