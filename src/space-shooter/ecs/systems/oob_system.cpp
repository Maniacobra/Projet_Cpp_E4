#include <space-shooter/ecs/systems/oob_system.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

    // OOB stands for "Out Of Bounds", this system checks what to do when sprites get close the border of the screen or cross past

    OOBSystem::OOBSystem()
        : System{
              type_list<SpriteComponent, PositionComponent>{} } {}

    void OOBSystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {

        for (auto e : entities) {
            assert(hasRequiredComponents(*e));

            const SpriteComponent& spr = e->get<SpriteComponent>();
            PositionComponent& pos = e->get<PositionComponent>();
            
            if (spr.oobAct == SpriteComponent::OOBAction::RemoveInvisible && // Remove the entities ouside the screen
                (pos.x + spr.width < 0 || pos.y + spr.height < 0
                    || pos.x - spr.width > manager.gameState().width || pos.y - spr.height > manager.gameState().height))
                e->kill();

            else if (spr.oobAct == SpriteComponent::OOBAction::Restrict) { // Restrict the position of entities close to the borders of the screen

                if (pos.x < 0)
                    pos.x = 0;
                else if (pos.x + spr.width > manager.gameState().width)
                    pos.x = manager.gameState().width - spr.width;
                if (pos.y < 0)
                    pos.y = 0;
                else if (pos.y + spr.height > manager.gameState().height)
                    pos.y = manager.gameState().height - spr.height;

            }
        }
    }

} // namespace space_shooter::ecs
