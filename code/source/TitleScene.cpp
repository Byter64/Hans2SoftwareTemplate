#include "TitleScene.h"
#include "MainScene.h"

using namespace Engine;

void TitleScene::DarkenColor(Color& color)
{
	color.SetRed(color.GetRed() / 2);
	color.SetGreen(color.GetGreen() / 2);
	color.SetBlue(color.GetBlue() / 2);
}

void TitleScene::DarkenImage(std::shared_ptr<Engine::Image> image)
{
	Color* color = image->GetData();
	for (; color < (image->GetData() + image->GetWidth() * image->GetHeight()); color++)
	{
		DarkenColor(*color);
	}
}

void TitleScene::OnStart()
{
	Systems::renderSystem->backgroundColor = Color(0, 0, 0);

	flashLogo = CreateEntity();
	ecsSystem->AddComponent<Name>(flashLogo) = "Flash Logo";
	ecsSystem->AddComponent<Transform>(flashLogo).SetTranslation(glm::vec2(200, 90));
	Sprite& sprite = ecsSystem->AddComponent<Sprite>(flashLogo);
	sprite.image = std::make_shared<Image>("assets/byterLogo.bmp");
	sprite.size = glm::ivec2(sprite.image->GetWidth(), sprite.image->GetHeight());

	titleText = CreateEntity();
	ecsSystem->AddComponent<Name>(titleText) = "Title Text";
	ecsSystem->AddComponent<Transform>(titleText).SetTranslation(glm::vec2(125, 155));
	Text& text = ecsSystem->AddComponent<Text>(titleText);
	text.text = "A Byte-Intensive Production";
	text.color = Color(31, 31, 31);
	text.font = Font::LoadFont("assets/Fonts/pixel-game/Pixel Game.otf");
}

void TitleScene::OnUpdate(float deltaTime)
{
	timer -= deltaTime;
	if (timer <= 0)
	{
		timer = TIME;
		DarkenImage(ecsSystem->GetComponent<Sprite>(flashLogo).image);
		DarkenColor(ecsSystem->GetComponent<Text>(titleText).color);
		darkenCounter++;
	}


	if (darkenCounter == 5)
	{
		sceneManager->LoadScene<MainScene>();
	}
}