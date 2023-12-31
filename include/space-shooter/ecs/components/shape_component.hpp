#pragma once

#include <space-shooter/ecs/component.hpp>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include <vector>
#include <initializer_list>

namespace space_shooter::ecs {

struct ShapeComponent : Component {

	enum class ShapeType {Circle, Rectangle};

	// Note : This component only supports circles for now, could be extended

	ShapeType type;
	float radius;
	sf::Color color;

	ShapeComponent() = default;
	ShapeComponent(ShapeType type, float radius /*change this*/, sf::Color color) : type{type}, radius{radius}, color{color} {}
};

} // namespace space_shooter::ecs