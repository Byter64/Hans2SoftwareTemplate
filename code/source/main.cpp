#include <memory>
#include "Engine.h"
#include "GlobalGameEvents.h"
#include "MainScene.h"

void OnStartGame(int screenWidth, int screenHeight)
{
	sceneManager->LoadScene<MainScene>();
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