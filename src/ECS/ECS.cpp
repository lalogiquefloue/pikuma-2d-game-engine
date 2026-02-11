#include "ECS.h"
#include "../Logger/Logger.h"

int IComponent::nextId = 0;

int Entity::GetId() const { return id; }

void System::AddEntityToSystem(Entity entity) { entities.push_back(entity); };

void System::RemoveEntityFromSystem(Entity entity) {
  entities.erase(
      std::remove_if(entities.begin(), entities.end(),
                     [&entity](Entity other) { return entity == other; }));
};

std::vector<Entity> System::GetSystemEntities() const { return entities; };

const Signature &System::GetComponentSignature() const {
  return componentSignature;
};

Entity Registry::CreateEntity() {
  int entityId;
  entityId = numEntities++;

  Entity entity(entityId);
  entity.registry = this;
  entitiesToBeAdded.insert(entity);

  if (entityId >= static_cast<int>(entityComponentSignatures.size())) {
    entityComponentSignatures.resize(entityId + 1);
  }

  Logger::Log("Entity created with id = " + std::to_string(entityId));

  return entity;
};

void Registry::AddEntityToSystems(Entity entity) {
  const auto entityId = entity.GetId();
  const auto &entityComponentSignature = entityComponentSignatures[entityId];

  for (auto &system : systems) {
    const auto &systemComponentSignature =
        system.second->GetComponentSignature(); // TODO: take some time to
                                                // better understand this

    bool isInterested = (entityComponentSignature & systemComponentSignature) ==
                        systemComponentSignature;

    if (isInterested) {
      system.second->AddEntityToSystem(entity);
    }
  }
};

void Registry::Update() {
  // Add entities to the active Systems
  for (auto entity : entitiesToBeAdded) {
    AddEntityToSystems(entity);
  }
  entitiesToBeAdded.clear();

  // TODO: remove the entities that are waiting to be killed from the active
  // Systems
};