#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/types.h>

namespace space_shooter::ecs {

    class EnemySpawnerEntity : public Entity {
    public:
        EnemySpawnerEntity(arch cooldown);
        EnemySpawnerEntity() = delete;
        using Entity::Entity;
    };

} // namespace space_shooter::ecs