#pragma once

namespace space_shooter::ecs {

struct Component {
  virtual ~Component() = default;
};

} // namespace space_shooter::ecs