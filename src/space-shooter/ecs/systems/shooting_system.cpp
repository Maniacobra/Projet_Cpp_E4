#include <space-shooter/ecs/systems/shooting_system.hpp>

#include <space-shooter/ecs/components/clock_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/shooting_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/entities/missile.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

ShootingSystem::ShootingSystem()
    : System{
            type_list<PositionComponent, ShootingComponent, SpriteComponent, ClockComponent>{} } {}

void ShootingSystem::update(const sf::Time& delta_time,
    std::vector<Entity*>& entities, Manager& manager) {

    for (auto e : entities) {
        assert(hasRequiredComponents(*e));

        const ShootingComponent& shoot = e->get<ShootingComponent>();
        const PositionComponent& pos = e->get<PositionComponent>();
        const SpriteComponent& spr = e->get<SpriteComponent>();
        ClockComponent& clk = e->get<ClockComponent>();

        clk.repeat = shoot.active; // No repeat when key not pressed

        if (shoot.active && clk.over)
            manager.registerEntity<MissileEntity>(sf::Vector2f(pos.x + spr.width / 2, pos.y + spr.height / 2), shoot.velocity, shoot.missileSize, shoot.missileColor);
    }
}

} // namespace space_shooter::ecs
