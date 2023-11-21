#include <space-shooter/ecs/systems/oob_system.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

    OOBSystem::OOBSystem()
        : System{
              type_list<SpriteComponent, PositionComponent>{} } {}

    void OOBSystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {

        for (auto e : entities) {
            assert(hasRequiredComponents(*e));

            const SpriteComponent& spr = e->get<SpriteComponent>();
            PositionComponent& pos = e->get<PositionComponent>();

            if (spr.removeOOB &&
                (pos.x + spr.width < 0 || pos.y + spr.height < 0
                    || pos.x - spr.width > manager.gameState().width || pos.y - spr.height > manager.gameState().height))
                e->kill(); // Exited the screen
        }
    }

} // namespace space_shooter::ecs
