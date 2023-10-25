#include <space-shooter/ecs/systems/movement_system.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/velocity_component.hpp>
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

    // const auto &vel = e->get<VelocityComponent>();
    // auto &pos = e->get<PositionComponent>();
    // const auto &input = e->get<InputComponent>();

    // TODO : update position coordinates depending on which input was triggered
    // the formula is simple : coord = coord +/- (velocity * deltatime)
    // the velocity needs to be > 100 to observe any significant change
  }
}

} // namespace space_shooter::ecs
