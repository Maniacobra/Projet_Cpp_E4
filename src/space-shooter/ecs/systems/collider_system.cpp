#include <space-shooter/ecs/systems/collider_system.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/tag_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>
#include <string>

namespace space_shooter::ecs {

    ColliderSystem::ColliderSystem()
        : System{
              type_list<PositionComponent, SpriteComponent, TagComponent>{} } {}

    void ColliderSystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {

        for (auto e : entities) {
            assert(hasRequiredComponents(*e));
            
            const PositionComponent pos = e->get<PositionComponent>();
            const SpriteComponent spr = e->get<SpriteComponent>();
            const TagComponent& tag = e->get<TagComponent>();

            if (tag.type == EntityTag::Player) {
                for (auto e2 : entities) {
                    assert(hasRequiredComponents(*e2));
                    const PositionComponent pos2 = e2->get<PositionComponent>();
                    const SpriteComponent spr2 = e2->get<SpriteComponent>();
                    const TagComponent& tag2 = e2->get<TagComponent>();

                    if (tag2.type == EntityTag::EnemyMissile) {

                        sf::FloatRect rect1(pos.x, pos.y, spr.width, spr.height);
                        sf::FloatRect rect2(pos2.x - spr2.width / 2, pos2.y - spr2.width / 2, spr2.width, spr2.height);

                        if (rect1.intersects(rect2)) {
                            std::cout << "Collide\n";
                            e2->kill();
                        }
                    }
                }
            }
        }
    }

} // namespace space_shooter::ecs
