#include <space-shooter/ecs/systems/movement_system.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

MovementSystem::MovementSystem()
    : System{
          type_list<VelocityComponent, PositionComponent, InputComponent>{}} {}

void MovementSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    const VelocityComponent& vel    = e->get<VelocityComponent>();
    const InputComponent&    inp    = e->get<InputComponent>();
    PositionComponent& pos   = e->get<PositionComponent>();
    const SpriteComponent& spr = e->get<SpriteComponent>();

    sf::Vector2<int> dir =  sf::Vector2<int>((int)inp.move_right - (int)inp.move_left, - (int)inp.move_top + (int)inp.move_bottom);
    double n             =  (dir.x + dir.y) != 0 ? sqrt(dir.x * dir.x + dir.y * dir.y) : 1;
    pos.x               +=  (dir.x * vel.vx * delta_time.asSeconds()) / n;
    pos.y               +=  dir.y  * vel.vy * delta_time.asSeconds()  / n;

    // Window borders
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

} // namespace space_shooter::ecs
