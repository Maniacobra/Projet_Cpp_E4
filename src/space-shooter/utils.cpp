#include <space-shooter/utils.hpp>

#include <optional>
#include <random>
#include <iostream>

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

std::string formatTime(long millis) {

    long total_seconds = millis / 1000;
    int min = total_seconds / 60;
    int sec = total_seconds % 60;
    int ms = (millis % 1000) / 10;

    std::ostringstream formatted_time;
    formatted_time << std::setw(2) << std::setfill('0') << min << ":"
        << std::setw(2) << std::setfill('0') << sec << ":"
        << std::setw(2) << std::setfill('0') << ms;

    return formatted_time.str();
}

} // namespace space_shooter
