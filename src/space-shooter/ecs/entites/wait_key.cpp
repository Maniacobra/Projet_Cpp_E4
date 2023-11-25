#include <space-shooter/ecs/entities/wait_key.hpp>

#include <space-shooter/ecs/components/key_scene_component.hpp>
#include <space-shooter/ecs/components/input_component.hpp>

#include <filesystem>

namespace space_shooter::ecs {

    // Entity for switching scenes

    WaitKeyEntity::WaitKeyEntity(KeySceneComponent::KeyEnum key, GameState::Scene scene, bool keepEntities) {
        add<KeySceneComponent>(key, scene, keepEntities);
        add<InputComponent>();
    }

} // namespace space_shooter::ecs
