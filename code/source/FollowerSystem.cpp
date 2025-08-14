#include "FollowerSystem.h"
#include "Follower.h"

using namespace Engine;

void FollowerSystem::EntityAdded(Engine::Entity entity)
{

}

void FollowerSystem::EntityRemoved(Engine::Entity entity)
{

}

void FollowerSystem::Update(float deltaTime)
{
	for (Entity entity : entities)
	{
		Transform& transform = ecsSystem->GetComponent<Transform>(entity);
		Follower& follower = ecsSystem->GetComponent<Follower>(entity);
		Transform& hauntedTransform = ecsSystem->GetComponent<Transform>(follower.hauntedEntity);

		int oldPointer = follower.queuePointer == 0 ? Follower::QUEUE_SIZE - 1 : follower.queuePointer - 1;
		glm::vec2 newPos = follower.positionQueue[oldPointer];
		glm::vec2 distance = hauntedTransform.GetGlobalTranslation() - newPos;
		glm::vec2 direction = glm::normalize(distance);
		if (direction != direction)
			direction = glm::vec2();


		transform.SetGlobalTranslation(follower.positionQueue[follower.queuePointer]);

		if (glm::length(distance) > Follower::TOLERANCE_RADIUS)
			newPos += direction * Follower::SPEED * deltaTime;
		follower.positionQueue[follower.queuePointer] = newPos;


		follower.queuePointer++;
		if (follower.queuePointer >= Follower::QUEUE_SIZE)
			follower.queuePointer = 0;
	}
}

void FollowerSystem::SetPosition(Engine::Entity entity, glm::vec2 position)
{
	Follower& follower = ecsSystem->GetComponent<Follower>(entity);
	for (int i = 0; i < Follower::QUEUE_SIZE; i++)
	{
		follower.positionQueue[i] = position;
	}
	follower.queuePointer = 0;
}