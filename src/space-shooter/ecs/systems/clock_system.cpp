#include <space-shooter/ecs/systems/clock_system.hpp>

#include <space-shooter/ecs/components/clock_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

    ClockSystem::ClockSystem()
        : System{
              type_list<ClockComponent>{} } {}

    void ClockSystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {

        for (auto e : entities) {
            assert(hasRequiredComponents(*e));

            ClockComponent& clk = e->get<ClockComponent>();
            clk.t -= delta_time.asMicroseconds();
            if (clk.t <= 0) {
                if (!clk.repeat)
                    clk.t = 0; // Constantly in "over" state until repeat is activated
                else
                    clk.t += clk.duration;
                clk.over = true;
            }
            else
                clk.over = false;
        }
    }

} // namespace space_shooter::ecs
