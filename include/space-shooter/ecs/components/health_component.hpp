#pragma once

#include <space-shooter/ecs/component.hpp>

namespace space_shooter::ecs {

struct HealthComponent : Component {

	int health;
	int maxHealth;

	HealthComponent() = default;
	HealthComponent(int health) : health{health}, maxHealth{health} {}
};

} // namespace space_shooter::ecs