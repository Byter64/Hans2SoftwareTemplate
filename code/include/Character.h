#pragma once

#include "Halib/Entity.h"

struct Character : public Halib::Entity
{
	static inline const char* const GRAPHIC_PATH = "assets/Mushroom-Run.bmp";
	const float speed;

	Character(float speed);
	void Update(float deltaTime) override;
};