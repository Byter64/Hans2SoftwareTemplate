#include <memory>
#include <iostream>
#include <Hall/Hall.h>
#include "Image.hpp"

static void ShowCoolTitle();
static void FinishFrame();
static void Clear(Hall::Color color);
static void Render(const std::shared_ptr<Image> image, short x, short y);

static Hall::Color CreateColor(char red, char green, char blue, bool alpha);
static Hall::Color SetRed(Hall::Color color, char red);
static Hall::Color SetGreen(Hall::Color color, char green);
static Hall::Color SetBlue(Hall::Color color, char blue);
static Hall::Color SetAlpha(Hall::Color color, bool alpha);
static char GetRed(Hall::Color color);
static char GetGreen(Hall::Color color);
static char GetBlue(Hall::Color color);
static bool GetAlpha(Hall::Color color);


static float currentTime;
static float targetFrameTime;
static float deltaTime;

int main()
{
	Hall::Init();

	currentTime = Hall::GetSystemTime() / (float)Hall::SYSTEM_CLK_FREQUENCY;
	targetFrameTime = 1 / 30.0f;
	deltaTime = targetFrameTime;

	ShowCoolTitle();
	
	Hall::Color bgColor = CreateColor(4, 1, 4, 1);
	while (!Hall::ShouldClose())
	{
		Clear(bgColor);
		FinishFrame();
	}

	return 0;
}

void ShowCoolTitle()
{
	std::shared_ptr<Image> image = std::make_shared<Image>("assets/byterLogo.bmp");

	std::shared_ptr<Hall::Color[]> data = std::make_shared<Hall::Color[]>(image->width * image->height);
	for (int i = 0; i < image->width * image->height; i++)
		data.get()[i] = image->data[i];

	std::shared_ptr<Image> titleScreen = std::make_shared<Image>();
	titleScreen->width = image->width;
	titleScreen->height = image->height;
	titleScreen->data = data;

	std::cout << "CoolTitle started" << std::endl;
	float timer = 3.0f;
	float time = 0.7f;
	int counter = 0;

	while (!Hall::ShouldClose() && counter < 5)
	{
		timer -= deltaTime;

		if (timer <= 0)
		{
			// Darken each pixel
			Hall::Color *color = titleScreen->data.get();
			for (; color < (titleScreen->data.get() + titleScreen->width * titleScreen->height); color++)
			{
				*color = SetRed(*color, GetRed(*color) / 2);
				*color = SetGreen(*color, GetGreen(*color) / 2);
				*color = SetBlue(*color, GetBlue(*color) / 2);
			}

			timer = time;
			counter++;
		}

		// RENDER CODE
		Clear(1);
		Render(titleScreen, 140, 60);
		FinishFrame();
		// RENDER CODE END
	}

	std::cout << "CoolTitle finished" << std::endl;
}

void FinishFrame()
{
	// Wait until GPU finished drawing
	while (Hall::GetIsGPUBusy())
		;

	// Wait until VSync is happening
	bool isVsync = Hall::GetVSync();
	bool newIsVsync = Hall::GetVSync();
	while (!(!isVsync && newIsVsync))
	{
		isVsync = newIsVsync;
		newIsVsync = Hall::GetVSync();
	}

	// Swap the frame buffers
	Hall::SetCommandSwapBuffers();

	// Wait until the target frame time has been reached
	float newTime = Hall::GetSystemTime() / (float)Hall::SYSTEM_CLK_FREQUENCY;
	while (newTime - currentTime < targetFrameTime)
	{
		newTime = Hall::GetSystemTime() / (float)Hall::SYSTEM_CLK_FREQUENCY;
	}

	deltaTime = newTime - currentTime;
	currentTime = newTime;
}


void Render(const std::shared_ptr<Image> image, short x, short y)
{

	// Wait until GPU is available
	while (Hall::GetIsGPUBusy())
		;

	Hall::Color *data = (Hall::Color *)image->data.get();
	Hall::SetImage(data, image->width, image->height);
	Hall::SetColorTable(Hall::CTType::NONE);
	Hall::SetColorSource(Hall::MEMORY);
	Hall::SetExcerpt(0, 0, image->width, image->height);
	Hall::SetScale(1, 1);
	Hall::SetFlip(false, false);
	Hall::SetScreenPosition(x, y);
	Hall::Draw();
}

void Clear(Hall::Color color)
{
	while (Hall::GetIsGPUBusy())
		;

	Hall::SetScale(1, 1);
	Hall::SetFlip(false, false);
	Hall::SetColor(color);
	Hall::SetColorTable(Hall::NONE);
	Hall::SetColorSource(Hall::COLOR);
	Hall::SetShape(Hall::RECTANGLE);
	Hall::SetRectangle(0, 0, Hall::SCREEN_WIDTH, Hall::SCREEN_HEIGHT);

	Hall::Draw();
}

static Hall::Color CreateColor(char red, char green, char blue, bool alpha)
{
	Hall::Color color = 0;
	color = SetRed(color, red);
	color = SetGreen(color, green);
	color = SetBlue(color, blue);
	color = SetAlpha(color, alpha);
	return color;
}

static Hall::Color SetRed(Hall::Color color, char red)
{
	return (color & 0b0000011111111111) | (((unsigned short)red & 0b11111) << 11);
}

static Hall::Color SetGreen(Hall::Color color, char green)
{
	return (color & 0b1111100000111111) | (((unsigned short)green & 0b11111) << 6);
}

static Hall::Color SetBlue(Hall::Color color, char blue)
{
	return (color & 0b1111111111000001) | (((unsigned short)blue & 0b11111) << 1);
}

static Hall::Color SetAlpha(Hall::Color color, bool alpha)
{
	unsigned short alphaVal = alpha ? 1 : 0;
	return (color & 0b1111111111111110) | alphaVal;
}

char GetRed(Hall::Color color)
{
	return (color >> 11) & 0b11111;
}

char GetGreen(Hall::Color color)
{
	return (color >> 6) & 0b11111;
}

char GetBlue(Hall::Color color)
{
	return (color >> 1) & 0b11111;
}

bool GetAlpha(Hall::Color color)
{
	return color & 0b1;
}
