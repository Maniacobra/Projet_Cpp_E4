#pragma once

#include <space-shooter/ecs/system.hpp>

#include <SFML/Graphics/Font.hpp>

#include <vector>

namespace space_shooter::ecs {

    class TextSystem : public System {
        sf::Font mainFont;
        bool fontsLoaded = false;
    public:
        TextSystem();
        void update(const sf::Time& /*delta_time*/, std::vector<Entity*>& entities,
            Manager& manager) override;
    };

} // namespace space_shooter::ecs