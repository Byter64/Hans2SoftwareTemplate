#pragma once
#include "Engine.h"

struct TitleScene : public Engine::Scene
{
	Engine::Entity flashLogo;
	Engine::Entity titleText;
	std::shared_ptr<Engine::Font> titleFont;
	static constexpr float TIME = 0.7f;
	float timer = 3.0f;
	int darkenCounter = 0;

	void DarkenColor(Engine::Color& color);
	void DarkenImage(std::shared_ptr<Engine::Image> image);

	//Add the title screen from my failed hans rpg
	//Test if text is working
	//Also maybe add a default font into the engine

	void OnStart() override;
    void OnUpdate(float deltaTime) override;
};