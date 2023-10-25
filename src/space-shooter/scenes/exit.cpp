#include <space-shooter/scenes/exit.hpp>

namespace space_shooter
{

  void exitGame(ecs::Manager& manager)
  {
    manager.gameState().running = false;
  }

} // namespace space_shooter
