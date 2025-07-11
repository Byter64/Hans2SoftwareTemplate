#pragma once
#include "Halib/Halib.h"

struct Rect : public Halib::Entity
{
	Halib::Color color;

	Rect(short width, short height, Halib::Color color);

	void Update(float deltaTime) override;
};