#include "Rect.h"

Rect::Rect(short width, short height, Halib::Color color) : Halib::Entity(Halib::Sprite(width, height, color), Halib::Vec3(20, 20, 0))
{

}

void Rect::Update(float deltaTime)
{

}