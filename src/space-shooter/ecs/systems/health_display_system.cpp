#include <space-shooter/ecs/systems/health_display_system.hpp>

#include <space-shooter/ecs/components/health_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {

    HealthBarDisplaySystem::HealthBarDisplaySystem()
        : System{
              type_list<HealthComponent, TagComponent>{} } {}

    void HealthBarDisplaySystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {

        for (auto e : entities) {
            assert(hasRequiredComponents(*e));
            ASSERT_TAG(e, EntityTag::Player);
            const HealthComponent& health = e->get<HealthComponent>();
            const TagComponent& tag = e->get<TagComponent>();

            float barHeight = 25.f;
            float barWidth = 200.f;
            float padding = 10.f;

            sf::RectangleShape rect(sf::Vector2f(barWidth, barHeight));
            rect.setPosition(sf::Vector2f(padding, manager.gameState().height - padding - barHeight));

            // Background
            rect.setFillColor(sf::Color::Black);
            manager.gameState().rendering_window->draw(rect);
            // Health
            if (health.health > 0) {
                sf::RectangleShape rectHealth(rect);
                rectHealth.setScale(sf::Vector2f((float)health.health / (float)health.maxHealth, 1.f));
                rectHealth.setFillColor(sf::Color(0, 150, 0, 255));
                manager.gameState().rendering_window->draw(rectHealth);
            }
            // Outline
            rect.setOutlineColor(sf::Color::Green);
            rect.setOutlineThickness(3);
            rect.setFillColor(sf::Color::Transparent);
            manager.gameState().rendering_window->draw(rect);
        }
    }

} // namespace space_shooter::ecs
