#include <space-shooter/ecs/systems/enemy_spawn_system.hpp>
#include <space-shooter/ecs/entities/enemy_spawner.hpp>
#include <space-shooter/ecs/entities/enemy_ship.hpp>

#include <space-shooter/ecs/components/all.hpp>

#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>
#include <cassert>

namespace space_shooter::ecs {

    EnemySpawnSystem::EnemySpawnSystem() : System{ type_list<ClockComponent, TagComponent>{} } {}

    void EnemySpawnSystem::update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) {
        for (auto e : entities) {   
            assert(hasRequiredComponents(*e));
            if (e->get<TagComponent>().type != EntityTag::EnemySpawner)
                continue;
            if (!e->get<ClockComponent>().over) continue;
            //Tick
            //Temporary to limit enemies
            static int maxNum = 5;
            static int num    = 0;
            //-----------------------       
            if (num > maxNum)
                return;

            manager.registerEntity<ecs::EnemyShipEntity>(sf::Vector2f(random(0, manager.gameState().width), 0), 100, 100, 
                    manager.gameState().config.path_to_textures / "ship0.png", 100.0f);
            ++num;
        }
    }

} // namespace space_shooter::ecs
