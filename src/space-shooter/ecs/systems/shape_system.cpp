#include <space-shooter/ecs/systems/shape_system.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/shape_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

ShapeSystem::ShapeSystem()
    : System(
        type_list<PositionComponent, ShapeComponent>{}) {}

void ShapeSystem::update(const sf::Time& /*delta_time*/,
    std::vector<Entity*>& entities,
    Manager& manager) {

    for (auto e : entities) {
        assert(hasRequiredComponents(*e));
        const auto& pos = e->get<PositionComponent>();
        const auto& shape = e->get<ShapeComponent>();

        sf::CircleShape circle(shape.radius);
        circle.setPosition(pos.asVec());
        circle.setFillColor(shape.color);

        manager.gameState().rendering_window->draw(circle);

    }
}

} // namespace space_shooter::ecs