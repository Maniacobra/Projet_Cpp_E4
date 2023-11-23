#include <space-shooter/ecs/entities/audio_player_entity.hpp>

#include <space-shooter/ecs/components/audio_component.hpp>
#include <filesystem>

namespace space_shooter::ecs {
    AudioPlayerEntity::AudioPlayerEntity(const std::filesystem::path& path, bool repeat) {
        add<AudioComponent>(path, repeat);
    }
} // namespace space_shooter::ecs
