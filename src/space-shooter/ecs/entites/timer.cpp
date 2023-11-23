#include <space-shooter/ecs/entities/timer.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>
#include <space-shooter/ecs/components/clock_component.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>

namespace space_shooter::ecs {

    TimerEntity::TimerEntity(arch millis) {
        add<PositionComponent>(10.f, 10.f);
        add<TextComponent>("--:--", 40, sf::Color::White, true);
        add<ClockComponent>(millis);
    }

} // namespace space_shooter::ecs
