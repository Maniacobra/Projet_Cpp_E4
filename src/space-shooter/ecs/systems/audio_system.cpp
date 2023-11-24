#include <space-shooter/ecs/systems/audio_system.hpp>

#include <space-shooter/ecs/components/audio_component.hpp>
#include <space-shooter/ecs/manager.hpp>
#include <space-shooter/game_state.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/Graphics.hpp>

#include <cassert>

namespace space_shooter::ecs {
    //TODO::Add volume and pitch?
    AudioSystem::AudioSystem() : System{ type_list<AudioComponent>{} } {}

    void AudioSystem::update(const sf::Time& delta_time,
        std::vector<Entity*>& entities, Manager& manager) {
        for (auto e : entities) {
              assert(hasRequiredComponents(*e));
                AudioComponent& au = e->get<AudioComponent>();
                //Create sound and play it
                if (!au.isPlaying) {
                    if (!au.sndBuf.loadFromFile(au.path.string())) {
                        printf("Can't open sound file.\n");
                        e->kill();
                        continue;
                    }
                    else {
                        au.snd.setBuffer(au.sndBuf);
                        au.snd.play();
                        au.isPlaying = true;
                    }
                }
                if (au.snd.getStatus() == sf::Sound::Playing) continue;
                //Sound isn't playing: either repeat or delete the entity...
                if (au.repeat) {
                    au.snd.play();
                    continue;
                }
                au.isPlaying = false;
                e->kill();
        }
    }
} // namespace space_shooter::ecs
