#include <space-shooter/ecs/systems/score_system.hpp>

#include <space-shooter/ecs/components/score_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

    ScoreSystem::ScoreSystem()
        : System(
            type_list<ScoreComponent, TextComponent>{}) {}

    void ScoreSystem::update(const sf::Time& /*delta_time*/,
        std::vector<Entity*>& entities,
        Manager& manager) {

        for (auto e : entities) {
            assert(hasRequiredComponents(*e));

            const ScoreComponent& scr = e->get<ScoreComponent>();
            TextComponent& text = e->get<TextComponent>();
            text.text.setString(std::to_string(scr.score));
        }
    }

} // namespace space_shooter::ecs