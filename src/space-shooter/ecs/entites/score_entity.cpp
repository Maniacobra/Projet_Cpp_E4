#include <space-shooter/ecs/entities/score_entity.hpp>

#include <space-shooter/ecs/components/score_component.hpp>
#include <space-shooter/ecs/components/text_component.hpp>
#include <space-shooter/ecs/components/position_component.hpp>

#include <filesystem>
#include <iostream>

namespace space_shooter::ecs {

    ScoreEntity::ScoreEntity() : scoreCmp{add<ScoreComponent>(0)} {
        add<PositionComponent>(10.f, 50.f);
        add<TextComponent>("-", 50, sf::Color::Green, true);
    }

    void ScoreEntity::addScore(int value) {
        scoreCmp.score += value;
    }

    int ScoreEntity::getScore() const {
        return scoreCmp.score;
    }

} // namespace space_shooter::ecs
