#pragma once

#include <space-shooter/ecs/entity.hpp>

#include <filesystem>
#include <memory>

namespace space_shooter::ecs {

    class AudioPlayerEntity : public Entity {
    public:
        AudioPlayerEntity(const std::filesystem::path& path, bool repeat);
        AudioPlayerEntity() = delete;

        using Entity::Entity;
    };

} // namespace space_shooter::ecs
