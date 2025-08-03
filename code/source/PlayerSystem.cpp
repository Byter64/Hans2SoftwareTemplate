#include "PlayerSystem.h"
#include "PlayerController.h"

using namespace Engine;

void PlayerSystem::EntityAdded(Engine::Entity entity)
{

}

void PlayerSystem::EntityRemoved(Engine::Entity entity)
{

}

void PlayerSystem::Update(float deltaTime)
{
	for(Entity entity : entities)
	{
		Transform& transform = ecsSystem->GetComponent<Transform>(entity);
		PlayerController& controller = ecsSystem->GetComponent<PlayerController>(entity);
		Animator& animator = ecsSystem->GetComponent<Animator>(entity);
		Animation& animation = ecsSystem->GetComponent<Animation>(entity);

		glm::ivec2 delta = glm::ivec2(0, 0);
		if(Input::GetButtonPressed(0, Input::Button::LEFT)) delta.x--;
		if(Input::GetButtonPressed(0, Input::Button::RIGHT)) delta.x++;
		if(Input::GetButtonPressed(0, Input::Button::UP)) delta.y--;
		if(Input::GetButtonPressed(0, Input::Button::DOWN)) delta.y++;

		//Add the position delta to the position
		transform.AddTranslation(glm::vec2(delta) * deltaTime * controller.speed);

		//The character should only animate, if he is moving
		animator.isPlaying = delta != glm::ivec2(0);

		//If the character is moving to the right, flip the sprite 
		if(delta.x != 0) 
		{
			glm::vec2 scale = transform.GetScale();
			scale.x = delta.x > 0 ? 1 : -1;
			transform.SetScale(scale);
		}

		if(delta == glm::ivec2(0, 0))
		{
			animator.timer = 0;
			animator.animationCounter = 0;
			animator.frameIndex = animation.animationStartIndex;
		}
	}
}