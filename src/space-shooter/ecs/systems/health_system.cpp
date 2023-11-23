#include <SFML/Window/Keyboard.hpp>
#include <space-shooter/ecs/systems/health_system.hpp>

#include <space-shooter/ecs/components/all.hpp>
#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/system.hpp>
#include <space-shooter/game_state.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

    HealthSystem::HealthSystem() : System{ type_list<HealthComponent, ColliderComponent>{} } {}

    void HealthSystem::update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) {


        for (auto e : entities) {
            assert(hasRequiredComponents(*e));
            ColliderComponent& col     = e->get<ColliderComponent>();
            HealthComponent&   health  = e->get<HealthComponent>();
            health.health              = fmax(0, health.health - fmin(col.hit, col.maxHitInOneFrame));

            if (health.health == 0)    e->kill();
            col.hit                    = 0;
        }
    }
} // namespace space_shooter::ecs