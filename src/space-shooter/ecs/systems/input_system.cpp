#include <SFML/Window/Keyboard.hpp>
#include <space-shooter/ecs/systems/input_system.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/system.hpp>
#include <space-shooter/game_state.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

    InputSystem::InputSystem() : System{ type_list<InputComponent>{} } {}

    void InputSystem::update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) {


        for (auto e : entities) {
            assert(hasRequiredComponents(*e));
            space_shooter::ecs::InputComponent& input = e->get<InputComponent>();
            input.escape = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
            input.enter = sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
            input.move_bottom = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
            input.move_right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
            input.move_top = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
            input.move_left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
            // TODO : reset detected input from keyboard (put all value of component to
            // false)
            // TODO: detect keypressed with SFML and set the boolean state accordingly
        }
    }

} // namespace space_shooter::ecs