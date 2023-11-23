#include <space-shooter/ecs/systems/enemy_controller_system.hpp>

#include <space-shooter/ecs/components/all.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

    EnemyControllerSystem::EnemyControllerSystem()
        : System{
              type_list<VelocityComponent, PositionComponent, SpriteComponent>{} } {}

    void EnemyControllerSystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {
        for (auto e : entities) {
            assert(hasRequiredComponents(*e));
            ASSERT_TAG(e, EntityTag::Enemy)
            VelocityComponent& vel = e->get<VelocityComponent>();
            PositionComponent& pos = e->get<PositionComponent>();
            SpriteComponent&   spr = e->get<SpriteComponent>();
            vel.vx = 0.0;
            if (vel.vy == 0)
                vel.vy = random(20.0, 100.0f);
            if (pos.y >= manager.gameState().height / 2)
                  vel.vy = 0;
        }
    }

} // namespace space_shooter::ecs
