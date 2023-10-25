#pragma once

#include <space-shooter/game_state.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

#include <fstream>
#include <memory>

namespace space_shooter {

size_t getNextUniqueID() noexcept;
// This is a utility function to get a unique ID for each type.
template <typename T> inline size_t getComponentTypeID() noexcept {
  static size_t type_ID =
      getNextUniqueID(); // nextTypeID is a global variable, initialized to 0.
  return type_ID;
}

std::unique_ptr<sf::RenderWindow>
initRenderingWindow(const std::string &title, std::size_t width,
                    std::size_t height, space_shooter::FrameRate frame_rate);

int random(int inf, int sup);
} // namespace space_shooter
