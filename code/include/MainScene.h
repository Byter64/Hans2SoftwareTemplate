#pragma once
#include <vector>
#include "Engine.h"

class MainScene : public Engine::Scene
{
    Engine::Entity player;
    std::vector<Engine::Entity> followers;

	void OnStart() override;
    void OnUpdate(float deltaTime) override;
    void OnUpdateWithoutPause() override;
    void OnEnd() override;

    Engine::Entity CreatePlayer();
    Engine::Entity CreateFollower(Engine::Entity hauntedEntity);
};