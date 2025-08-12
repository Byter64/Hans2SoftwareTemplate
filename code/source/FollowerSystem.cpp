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


		transform.SetGlobalTranslation(follower.positionQueue[follower.queuePointer]);


		glm::vec2 distance = transform.GetGlobalTranslation() - hauntedTransform.GetGlobalTranslation();
		glm::vec2 newPos = transform.GetGlobalTranslation();
		if (glm::length(distance) > Follower::TOLERANCE_RADIUS)
			newPos += glm::normalize(distance) * Follower::SPEED;
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