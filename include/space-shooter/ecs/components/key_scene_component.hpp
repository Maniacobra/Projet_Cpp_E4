#pragma once

#include <space-shooter/ecs/component.hpp>
#include <space-shooter/game_state.hpp>

namespace space_shooter::ecs {

struct KeySceneComponent : Component {

	enum class KeyEnum {ENTER, ESCAPE};
	
	KeyEnum key;
	GameState::Scene scene;

	KeySceneComponent() = default;
	KeySceneComponent(KeyEnum key, GameState::Scene scene) : key{key}, scene{scene} {}
};

} // namespace space_shooter::ecs