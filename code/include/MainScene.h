#pragma once
#include "Engine.h"

class MainScene : public Engine::Scene
{
	void OnStart() override;
    void OnUpdate(float deltaTime) override;
    void OnUpdateWithoutPause() override;
    void OnEnd() override;
};