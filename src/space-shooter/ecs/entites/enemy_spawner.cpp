#include <space-shooter/ecs/entities/enemy_spawner.hpp>
#include <space-shooter/ecs/components/all.hpp>

namespace space_shooter::ecs {
    EnemySpawnerEntity::EnemySpawnerEntity(arch cooldown) {
        add<ClockComponent>(cooldown);
        add<TagComponent>(EntityTag::EnemySpawner);
    }

} // namespace space_shooter::ecs