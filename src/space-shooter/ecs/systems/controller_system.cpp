#include <space-shooter/ecs/systems/controller_system.hpp>

#include <space-shooter/ecs/components/controllable_component.hpp>
#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>
#include <space-shooter/ecs/components/shooting_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

    // This system makes the link between inputs and the player actions

ControllerSystem::ControllerSystem()
    : System{
          type_list<ControllableComponent, VelocityComponent, PositionComponent, InputComponent, SpriteComponent, ShootingComponent>{}} {}

void ControllerSystem::update(const sf::Time &delta_time,
                            std::vector<Entity *> &entities, Manager &manager) {

  for (auto e : entities) {
    assert(hasRequiredComponents(*e));

    const ControllableComponent ctr = e->get<ControllableComponent>();
    VelocityComponent& vel    = e->get<VelocityComponent>();
    const InputComponent&    inp    = e->get<InputComponent>();
    PositionComponent& pos   = e->get<PositionComponent>();
    const SpriteComponent& spr = e->get<SpriteComponent>();
    ShootingComponent& shoot = e->get<ShootingComponent>();

    // Change velocity
    sf::Vector2<int> dir =  sf::Vector2<int>((int)inp.move_right - (int)inp.move_left, - (int)inp.move_top + (int)inp.move_bottom);
    double n             =  (dir.x + dir.y) != 0 ? sqrt(dir.x * dir.x + dir.y * dir.y) : 1;
    vel.vx = dir.x * ctr.speed / n;
    vel.vy = dir.y * ctr.speed / n;

    // Shoot
    shoot.active = inp.shoot;
    
  }
}

} // namespace space_shooter::ecs
