#pragma once

#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/components/score_component.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

	class ScoreEntity : public Entity {
		ScoreComponent& scoreCmp;
	public:
		ScoreEntity();
		void addScore(int value);
		int getScore() const;

		using Entity::Entity;
	};

} // namespace space_shooter::ecs
