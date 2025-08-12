#include "MainScene.h"
#include "Systems.h"
#include "PlayerController.h"
#include "Follower.h"


using namespace Engine;


void MainScene::OnStart()
{
	player = CreatePlayer();
	followers.push_back(CreateFollower(player));
	followers.push_back(CreateFollower(followers[0]));
}

void MainScene::OnUpdate(float deltaTime)
{
	playerSystem->Update(deltaTime);
	followerSystem->Update(deltaTime);
}

void MainScene::OnUpdateWithoutPause()
{

}

void MainScene::OnEnd()
{

}

Entity MainScene::CreatePlayer()
{
	//Create Entity and its components
	player = CreateEntity();

	Name& name = ecsSystem->AddComponent<Name>(player);
	name = "Player";

	Transform& transform = ecsSystem->AddComponent<Transform>(player);
	transform.SetTranslation(glm::vec2(100, 100));

	SpriteRenderer& renderer = ecsSystem->AddComponent<SpriteRenderer>(player);
	renderer.ctType = Hall::CTType::NONE;
	renderer.image = std::make_shared<Image>(Files::ASSETS / "Mushroom-Run.bmp");
	renderer.isActive = true;
	renderer.offset = glm::ivec2(0, 0);
	renderer.size = glm::ivec2(80, 64);

	Animator& animator = ecsSystem->AddComponent<Animator>(player);
	animator.animationCounter = 0;
	animator.frameIndex = glm::ivec2(0, 0);
	animator.framesPerSecond = 10;
	animator.isPlaying = false;
	animator.timer = 0;

	Animation& animation = ecsSystem->AddComponent<Animation>(player);
	animation.animationDirection = Animation::RIGHT;
	animation.animationFrameCount = 8;
	animation.frameCount = glm::ivec2(8, 1);
	animation.animationStartIndex = glm::ivec2(0, 0);

	PlayerController& controller = ecsSystem->AddComponent<PlayerController>(player);

	return player;
}

Entity MainScene::CreateFollower(Entity hauntedEntity)
{
	Entity entity = CreateEntity();

	Transform& transform = ecsSystem->AddComponent<Transform>(entity);
	transform.SetGlobalTranslation(glm::vec2(-100, -100));
	
	Follower& follower = ecsSystem->AddComponent<Follower>(entity);
	follower.hauntedEntity = hauntedEntity;

	RectangleRenderer& renderer = ecsSystem->AddComponent<RectangleRenderer>(entity);
	renderer.size = glm::ivec2(20, 20);
	renderer.color = Color(10, 15, 20);

	return entity;
}