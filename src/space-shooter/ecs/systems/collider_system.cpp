#include <space-shooter/ecs/systems/collider_system.hpp>

#include <space-shooter/ecs/components/all.hpp>

#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>
#include <string>

namespace space_shooter::ecs {
    ColliderSystem::ColliderSystem() : System{ type_list<PositionComponent, SpriteComponent, TagComponent, ColliderComponent>{} } {}

    bool ColliderSystem::AABB(sf::FloatRect rect0, sf::FloatRect rect1) {
        bool xx = rect0.getPosition().x < (rect1.getPosition().x + rect1.getSize().x) && rect1.getPosition().x < (rect0.getPosition().x + rect0.getSize().x);
        bool yy = rect0.getPosition().y < (rect1.getPosition().y + rect1.getSize().y) && rect1.getPosition().y < (rect0.getPosition().y + rect0.getSize().y);
        return xx && yy;
    }


    //Collision is resolved if e1 has e1tag and e2[i] has e2tag ALWAYS E2[i] IS KILLED!
    bool ColliderSystem::ResolveCollision(Entity* e1, std::vector<Entity*>& e2, EntityTag e1tag, EntityTag e2tag) {
        bool ret = false;
        if (e1->get<TagComponent>().type != e1tag) return false;
        for (Entity* e0 : e2) {
            //Not valid colliders objects-----------
            if (e1 == e0) continue;
            assert(hasRequiredComponents(*e0));
            ASSERT_TAG(e0, e2tag);
            if (e0->get<TagComponent>().type != e2tag) continue;
            //Collisison can occur---------------------
            auto e1pos = e1->get<PositionComponent>(); auto e0pos = e0->get<PositionComponent>();
            auto e1spr = e1->get<SpriteComponent>();   auto e0spr = e0->get<SpriteComponent>();

            sf::FloatRect rect1(e1pos.x, e1pos.y, e1spr.width, e1spr.height);
            sf::FloatRect rect2(e0pos.x, e0pos.y, e0spr.width, e0spr.height); //Offset of circles shouldnt be computed here

            if (!AABB(rect1, rect2)) continue;
            //Collision occurs
            ++e0->get<ColliderComponent>().hit;
            ++e1->get<ColliderComponent>().hit;
            ret = true;
        }
        return ret;
    }

    void ColliderSystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {

        for (auto e : entities) {
            assert(hasRequiredComponents(*e));        
            if (ResolveCollision(e, entities, EntityTag::Player, EntityTag::EnemyMissile))  continue;
            if (ResolveCollision(e, entities, EntityTag::Enemy,  EntityTag::PlayerMissile)) continue;
        }
    }
}
