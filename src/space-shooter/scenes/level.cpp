#include <space-shooter/scenes/level.hpp>

#include <space-shooter/ecs/ecs.hpp>

namespace space_shooter {

void initLevel(ecs::Manager &manager) {
  // TODO
  manager.gameState().switch_to_scene = GameState::Scene::Score;
}
} // namespace space_shooter
