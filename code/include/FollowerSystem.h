#pragma once
#include "Engine.h"

struct FollowerSystem : public Engine::System
{

	void EntityAdded(Engine::Entity entity) override;
	void EntityRemoved(Engine::Entity entity) override;

	void Update(float deltaTime);

	void SetPosition(Engine::Entity entity, glm::vec2 position);
};