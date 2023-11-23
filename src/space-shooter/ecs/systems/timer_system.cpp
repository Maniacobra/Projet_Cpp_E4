#include <space-shooter/ecs/systems/timer_system.hpp>

#include <space-shooter/ecs/components/clock_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

    TimerSystem::TimerSystem()
        : System{
              type_list<ClockComponent, TextComponent>{} } {}

    void TimerSystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {

        for (auto e : entities) {
            assert(hasRequiredComponents(*e));

            const ClockComponent& clk = e->get<ClockComponent>();
            TextComponent& text = e->get<TextComponent>();
            text.text.setString(formatTime(clk.t / 1000));

            if (clk.over) {
                manager.gameState().switch_to_scene = GameState::Scene::Score;
            }
        }
    }

} // namespace space_shooter::ecs
