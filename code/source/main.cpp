#include <memory>
#include "Engine.h"
#include "GlobalGameEvents.h"

#include "Systems.h"
#include "TitleScene.h"
#include "PlayerController.h"
#include "PlayerSystem.h"
#include "Follower.h"
#include "FollowerSystem.h"

using namespace Engine;

static void RegisterToECS();

void OnStartGame(int screenWidth, int screenHeight)
{
	RegisterToECS();
	sceneManager->LoadScene<TitleScene>();
}

void Update(float deltaTime)
{

}

void UpdateWithoutPause()
{

}

void OnEndGame()
{

}

static void RegisterToECS()
{
	//Register a custom component
	ecsSystem->RegisterComponent<PlayerController>();
	ecsSystem->RegisterComponent<Follower>();

	//Register a custom system and set the components an entity needs to be processed by that system
	playerSystem = ecsSystem->RegisterSystem<PlayerSystem>();
	Signature playerSystemSignature;
	playerSystemSignature.set(ecsSystem->GetComponentType<Transform>());
	playerSystemSignature.set(ecsSystem->GetComponentType<PlayerController>());
	playerSystemSignature.set(ecsSystem->GetComponentType<Animator>());
	playerSystemSignature.set(ecsSystem->GetComponentType<Animation>());
	ecsSystem->AddSystemSignature<PlayerSystem>(playerSystemSignature);

	followerSystem = ecsSystem->RegisterSystem<FollowerSystem>();
	Signature followerSystemSignature;
	followerSystemSignature.set(ecsSystem->GetComponentType<Transform>());
	followerSystemSignature.set(ecsSystem->GetComponentType<Follower>());
	ecsSystem->AddSystemSignature<FollowerSystem>(followerSystemSignature);
}