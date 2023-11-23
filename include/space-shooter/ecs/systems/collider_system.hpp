#pragma once

#include <space-shooter/ecs/system.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>

#include <SFML/Graphics/Rect.hpp>
#include <vector>

namespace space_shooter::ecs {
    
    class ColliderSystem : public System {
    public:
        ColliderSystem();
        
        //returns true two rectangles are intersecting
        bool AABB(sf::FloatRect rect0, sf::FloatRect rect1);

        bool ResolveCollision(Entity* e1, std::vector<Entity*>& e2, EntityTag e1tag, EntityTag e2tag);

        void update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) override;
    };
} // namespace space_shooter::ecs