#pragma once

#include <space-shooter/ecs/system.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>

#include <vector>

namespace space_shooter::ecs {

    class ColliderSystem : public System {
    public:
        ColliderSystem();
        

        bool ResolveCollision(Entity* e1, std::vector<Entity*>& e2, EntityTag e1tag, EntityTag e2tag);

        void update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) override;
    };
} // namespace space_shooter::ecs