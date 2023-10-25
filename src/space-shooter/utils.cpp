#include <space-shooter/utils.hpp>

#include <optional>
#include <random>

namespace space_shooter {

size_t getNextUniqueID() noexcept {
  static size_t current_type_ID = 0;
  return current_type_ID++;
}

std::unique_ptr<sf::RenderWindow>
initRenderingWindow(const std::string &title, std::size_t width,
                    std::size_t height, space_shooter::FrameRate frame_rate) {
  auto window = std::unique_ptr<sf::RenderWindow>{
      new sf::RenderWindow(sf::VideoMode({static_cast<unsigned>(width),
                                          static_cast<unsigned>(height)}),
                           title)};

  if (frame_rate == space_shooter::FrameRate::VERTICAL_SYNC)
    window->setVerticalSyncEnabled(true);
  else if (frame_rate == space_shooter::FrameRate::LIMIT_FPS)
    window->setFramerateLimit(FPS_LIMIT);

  return window;
}

int random(int inf, int sup) {
  static auto rd = std::random_device{};
  static auto rng = std::default_random_engine{rd()};

  auto dist = std::uniform_int_distribution<int>(inf, sup);
  return dist(rng);
}
} // namespace space_shooter
