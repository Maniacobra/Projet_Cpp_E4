#include <space-shooter/ecs/systems/rendering_system.hpp>

#include <space-shooter/ecs/components/position_component.hpp>
#include <space-shooter/ecs/components/sprite_component.hpp>
#include <space-shooter/ecs/components/texture_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>
#include <iostream>

namespace space_shooter::ecs {

RenderingSystem::RenderingSystem()
    : System(
          type_list<TextureComponent, PositionComponent, SpriteComponent>{}) {}

void RenderingSystem::update(const sf::Time & /*delta_time*/,
                             std::vector<Entity *> &entities,
                             Manager &manager) {
  for (auto e : entities) {
    assert(hasRequiredComponents(*e));
    const auto& pos = e->get<PositionComponent>();
    const auto& spr = e->get<SpriteComponent>();
    auto& tex = e->get<TextureComponent>();

    // DONE: load texture (if needed) into the texture component
    // DONE: then set boolean of component to true
    if (!tex.loaded && tex.texture.loadFromFile(tex.texture_path.string())) 
        tex.loaded = 1;

    sf::Sprite sfml_sprite;
    sfml_sprite.setTexture(tex.texture);
    sfml_sprite.setPosition(pos.x, pos.y);
    
    manager.gameState().rendering_window->draw(sfml_sprite);
    
    // TODO build SFML sprite to render the texture
    // TODO render the sprite at the correct position via manager -> game state
    // -> rendering window -> draw

    
  }
}

} // namespace space_shooter::ecs