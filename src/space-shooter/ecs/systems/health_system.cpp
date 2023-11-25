#include <SFML/Window/Keyboard.hpp>
#include <space-shooter/ecs/systems/health_system.hpp>

#include <space-shooter/ecs/entities/score_entity.hpp>
#include <space-shooter/ecs/components/all.hpp>
#include <space-shooter/ecs/entity.hpp>
#include <space-shooter/ecs/entities/audio_player_entity.hpp>
#include <space-shooter/ecs/system.hpp>
#include <space-shooter/game_state.hpp>

#include <space-shooter/ecs/manager.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

    HealthSystem::HealthSystem() : System{ type_list<HealthComponent, ColliderComponent, TagComponent>{} } {}

    void HealthSystem::update(const sf::Time& delta_time, std::vector<Entity*>& entities, Manager& manager) {

        for (auto e : entities) {
            assert(hasRequiredComponents(*e));
            ColliderComponent& col     = e->get<ColliderComponent>();
            HealthComponent&   health  = e->get<HealthComponent>();
            TagComponent& tag          = e->get<TagComponent>();
            health.health              = fmax(0, health.health - fmin(col.hit, col.maxHitInOneFrame)); // Decreases health

            if (health.health == 0) { // Entity dies
                e->kill();

                switch (tag.type)
                {
                case EntityTag::Player:
                    manager.gameState().switch_to_scene = GameState::Scene::GameOver;
                    manager.gameState().keep_entities = true;
                    break;
                case EntityTag::Enemy:
                    manager.sendToEntity<ScoreEntity>(
                        [](ScoreEntity& scoreEnt) {
                            scoreEnt.addScore(10);
                        } // Increase score +10
                    );
                    break;
                case EntityTag::PlayerMissile:
                case EntityTag::EnemyMissile:
                    manager.registerEntity<ecs::AudioPlayerEntity>(manager.gameState().config.path_to_audio / "Death.wav", false); //Not best place to do this
                }
            }

            col.hit                    = 0;
        }
    }
} // namespace space_shooter::ecs