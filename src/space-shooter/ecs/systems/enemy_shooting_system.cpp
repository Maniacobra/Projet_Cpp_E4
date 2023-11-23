#include <space-shooter/ecs/systems/enemy_shooting_system.hpp>

#include <space-shooter/ecs/components/all.hpp>
#include <space-shooter/ecs/entities/missile.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

    EnemyShootingSystem::EnemyShootingSystem()
        : System{
                type_list<PositionComponent, ShootingComponent, SpriteComponent, ClockComponent, TagComponent>{} } {}

    void EnemyShootingSystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {

        for (auto e : entities) {
            assert(hasRequiredComponents(*e));
            ASSERT_TAG(e, EntityTag::Enemy);
            const ShootingComponent& shoot = e->get<ShootingComponent>();
            const PositionComponent& pos   = e->get<PositionComponent>();
            const SpriteComponent&   spr   = e->get<SpriteComponent>();
            ClockComponent&          clk   = e->get<ClockComponent>();
            if (!shoot.active || !clk.over) continue;
            Entity& m = manager.registerEntity<MissileEntity>(sf::Vector2f(pos.x + spr.width / 2, pos.y + spr.height / 2), shoot.velocity, 
                                                                           shoot.missileSize, shoot.missileColor, shoot.missileTag);
        }
    }
}
