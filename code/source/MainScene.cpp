#include "MainScene.h"
#include "PlayerSystem.h"
#include "PlayerController.h"

using namespace Engine;

Entity player;
std::shared_ptr<PlayerSystem> playerSystem;

void MainScene::OnStart()
{
	ecsSystem->RegisterComponent<PlayerController>();
	playerSystem = ecsSystem->RegisterSystem<PlayerSystem>();
	Signature playerSystemSignature;
    playerSystemSignature.set(ecsSystem->GetComponentType<Transform>());
    playerSystemSignature.set(ecsSystem->GetComponentType<PlayerController>());
    playerSystemSignature.set(ecsSystem->GetComponentType<Animator>());
    playerSystemSignature.set(ecsSystem->GetComponentType<Animation>());
    ecsSystem->AddSystemSignature<PlayerSystem>(playerSystemSignature);


	player = ecsSystem->CreateEntity();

	Transform& transform = ecsSystem->AddComponent<Transform>(player);
	transform.SetTranslation(glm::vec2(0));
	
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
	controller.speed = 50.0f;
}

void MainScene::OnUpdate(float deltaTime)
{
	playerSystem->Update(deltaTime);
}

void MainScene::OnUpdateWithoutPause()
{

}

void MainScene::OnEnd()
{

}
