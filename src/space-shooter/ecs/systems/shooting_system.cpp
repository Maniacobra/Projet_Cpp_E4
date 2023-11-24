#include <space-shooter/ecs/systems/shooting_system.hpp>

#include <space-shooter/ecs/entities/player_ship.hpp>
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
            type_list<PositionComponent, ShootingComponent, SpriteComponent, ClockComponent, TagComponent>{} } {}

void ShootingSystem::update(const sf::Time& delta_time,
    std::vector<Entity*>& entities, Manager& manager) {
    for (auto e : entities) {
        assert(hasRequiredComponents(*e));

        const ShootingComponent& shoot = e->get<ShootingComponent>();
        const PositionComponent& pos   = e->get<PositionComponent>();
        const SpriteComponent& spr     = e->get<SpriteComponent>();
        ClockComponent& clk            = e->get<ClockComponent>();

        if (clk.repeat != shoot.active)
            clk.t = clk.duration; // Reset clock
        clk.repeat = shoot.active; // No repeat when key not pressed

        if (shoot.active && clk.over) {

            sf::Vector2f direction = shoot.velocity;

            if (shoot.targetPlayer) {

                auto positionComponent = manager.getFromEntity<PlayerShipEntity>(
                    [](PlayerShipEntity& ship) {return ship.getPos(); }
                );
                if (positionComponent) {
                    
                    float s = sqrt(shoot.velocity.x * shoot.velocity.x + shoot.velocity.y * shoot.velocity.y);

                    float playerX = positionComponent->x;
                    float playerY = positionComponent->y;

                    // Calculate direction vector
                    sf::Vector2f toPlayer(playerX - pos.x, playerY - pos.y);
                    float length = sqrt(toPlayer.x * toPlayer.x + toPlayer.y * toPlayer.y);

                    // Normalize and scale by speed
                    if (length != 0) {
                        direction = sf::Vector2f(toPlayer.x / length, toPlayer.y / length) * s;
                    }
                }

            }

            manager.registerEntity<MissileEntity>(sf::Vector2f(pos.x + spr.width / 2, pos.y + spr.height / 2),
                direction, shoot.missileSize, shoot.missileColor, shoot.missileTag);
        }
    }
}

} // namespace space_shooter::ecs
