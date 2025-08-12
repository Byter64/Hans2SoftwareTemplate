#pragma once
#include "Engine.h"
#include "PlayerController.h"

struct Follower
{
	static constexpr int QUEUE_SIZE = 60;
	static constexpr float TOLERANCE_RADIUS = 30;
	static constexpr float SPEED = PlayerController::SPEED;

	Engine::Entity hauntedEntity;

	glm::vec2 positionQueue[QUEUE_SIZE];
	unsigned char queuePointer = 0;
};