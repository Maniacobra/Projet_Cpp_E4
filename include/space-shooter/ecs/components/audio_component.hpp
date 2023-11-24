#pragma once

#include <space-shooter/ecs/component.hpp>
#include <space-shooter/types.h>
#include <SFML/Audio.hpp>
#include <filesystem>

namespace space_shooter::ecs {
	struct AudioComponent : Component {
		sf::SoundBuffer sndBuf;
		sf::Sound   snd;
		std::filesystem::path path;
		bool repeat      = true;
		bool isPlaying   = false;
		AudioComponent(const std::filesystem::path& path, bool repeat) : repeat{repeat}, path{path} {}
		AudioComponent() = default;
	};
} // namespace space_shooter::ecs