#pragma once

#include <space-shooter/ecs/components/key_scene_component.hpp>
#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/game_state.hpp>

#include <filesystem>
#include <memory>

#include <SFML/Window/Keyboard.hpp>

namespace space_shooter::ecs {

    class WaitKeyEntity : public Entity {
    public:
        WaitKeyEntity(KeySceneComponent::KeyEnum key, GameState::Scene scene);
        WaitKeyEntity() = delete;

        using Entity::Entity;
    };

} // namespace space_shooter::ecs