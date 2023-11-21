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
    if (!tex.loaded && tex.texture.loadFromFile(tex.texture_path.string())) {
        tex.loaded = 1;
    }

    sf::Sprite sfml_sprite;
    sfml_sprite.setTexture(tex.texture);
    sfml_sprite.setPosition(pos.x, pos.y);
    if (spr.resize == SpriteComponent::Resize::Scale)
        sfml_sprite.setScale((float)spr.width / (float)tex.texture.getSize().x, (float)spr.height / (float)tex.texture.getSize().x);
    else if (spr.resize == SpriteComponent::Resize::None)
        sfml_sprite.setTextureRect(sf::IntRect(0, 0, spr.width, spr.height)); // Crop by the top left corner
    
    manager.gameState().rendering_window->draw(sfml_sprite);
  }
}

} // namespace space_shooter::ecs