#include <space-shooter/ecs/entities/background.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>

#include <filesystem>

namespace space_shooter::ecs {

BackgroundEntity::BackgroundEntity(const std::filesystem::path &texture_path,
                                   int window_width, int window_height) {
  add<PositionComponent>(0.f, 0.f);
  add<TextureComponent>(texture_path, true);
  add<SpriteComponent>(window_width, window_height);
}

} // namespace space_shooter::ecs
