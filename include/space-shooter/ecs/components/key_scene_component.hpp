#pragma once

#include <space-shooter/ecs/component.hpp>
#include <space-shooter/game_state.hpp>

namespace space_shooter::ecs {

struct KeySceneComponent : Component {

	enum class KeyEnum {Enter, Escape};
	
	bool isReleased = false;
	KeyEnum key;
	GameState::Scene scene;
	bool keepEntities;

	KeySceneComponent() = default;
	KeySceneComponent(KeyEnum key, GameState::Scene scene, bool keepEntities) : key{key}, scene{scene}, keepEntities{keepEntities} {}
};

} // namespace space_shooter::ecs