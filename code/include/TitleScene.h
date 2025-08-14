#pragma once
#include "Engine.h"

struct TitleScene : public Engine::Scene
{
	//Add the title screen from my failed hans rpg
	//Test if text is working
	//Also maybe add a default font into the engine

	void OnStart() override;
    void OnUpdate(float deltaTime) override;
    void OnUpdateWithoutPause() override;
    void OnEnd() override;
};