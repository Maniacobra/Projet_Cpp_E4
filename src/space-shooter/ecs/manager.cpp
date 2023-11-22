#include <space-shooter/ecs/manager.hpp>

#include <space-shooter/game_state.hpp>
#include <space-shooter/scenes/all.hpp>
#include <space-shooter/utils.hpp>

#include <SFML/System/Time.hpp>

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace space_shooter::ecs {

Manager::Manager(const GameConfig &game_config)
    : game_state_(initGameState(game_config)) {}

GameState &Manager::gameState() { return *game_state_; }
const GameState &Manager::gameState() const { return *game_state_; }

void Manager::update(const sf::Time &delta_time) {
  // if a scene switch was triggered
  if (game_state_->switch_to_scene != GameState::Scene::None) {
    triggerSceneChange();
  }

  for (auto &system : systems_) {
    if (system->isEnabled()) {
      auto relevant_entities = filterEntitiesForSystem(system.get());
      system->update(delta_time, relevant_entities, *this);
    }
  }

  // collect and remove dead systems & dead entities
  std::erase_if(systems_,
                [](const auto &system) { return !system->isAlive(); });
  std::erase_if(entities_,
                [](const auto &entity) { return !entity->isAlive(); });
}

std::vector<Entity*> Manager::filterEntitiesForSystem(System *system) {
  std::vector<Entity*> relevant_entities;

  const auto &requirements = system->getRequiredComponents();
  for (auto &entity : entities_) {
    bool all_components_found = true;

    for (auto &requirement : requirements) {
      if (!entity->hasComponentWithID(requirement)) {
        all_components_found = false;
        break;
      }
    }

    if (all_components_found) {
      relevant_entities.push_back(entity.get());
    }
  }

  return relevant_entities;
}

void Manager::clearEntities() { entities_.clear(); }

void Manager::clearSystems() { systems_.clear(); }

void Manager::clearAll() {
  clearEntities();
  clearSystems();
}

void Manager::disableAllSystems() {
  for (auto &sys : systems_) {
    sys->disable();
  }
}

void Manager::enableAllSystems() {
  for (auto &sys : systems_) {
    sys->enable();
  }
}

void Manager::triggerSceneChange() {
  // clear all entities and systems if needed
  if (!(game_state_->keep_entities)) {
    clearEntities();
  }

  if (!(game_state_->keep_systems)) {
    clearSystems();
  }

  auto switch_to_scene = game_state_->switch_to_scene;

  game_state_->keep_entities = false;
  game_state_->keep_systems = false;
  game_state_->switch_to_scene = GameState::Scene::None;

  // launch the scene switch
  switch (switch_to_scene) {
  case GameState::Scene::Level:
    initLevel(*this);
    break;
  case GameState::Scene::Exit:
    exitGame(*this);
    break;
  case GameState::Scene::Menu:
    initMenu(*this);
    break;
  case GameState::Scene::Score:
    initScore(*this);
    break;
  default:
    initLevel(*this);
    break;
  }
}

} // namespace space_shooter::ecs