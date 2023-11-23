#include <space-shooter/ecs/systems/wait_key_system.hpp>

#include <space-shooter/ecs/components/input_component.hpp>
#include <space-shooter/ecs/components/key_scene_component.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

	WaitKeySystem::WaitKeySystem()
		: System(type_list<KeySceneComponent, InputComponent>{}) {}

	void WaitKeySystem::update(const sf::Time&, std::vector<Entity*>& entities, Manager& manager) {

		for (auto e : entities) {
			assert(hasRequiredComponents(*e));
			const InputComponent& input = e->get<InputComponent>();
			const KeySceneComponent& keyScene = e->get<KeySceneComponent>();

			if (keyScene.key == KeySceneComponent::KeyEnum::Enter && input.enter
				|| keyScene.key == KeySceneComponent::KeyEnum::Escape && input.escape)
				manager.gameState().switch_to_scene = keyScene.scene;
		}
	}
}