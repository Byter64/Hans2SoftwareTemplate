#include "Character.h"
#include "Halib/Graphic.h"
#include "Halib/System.h"
#include <iostream>
using namespace Halib;

Character::Character(float speed) : Entity(Sprite(GRAPHIC_PATH, VecI2(8, 1)), Vec3(200, 120, 0)), speed(speed)
{
	sprite.SetupAnimation(VecI2(0, 0), 8, 10);
}

void Character::Update(float deltaTime)
{
	VecI2 delta = VecI2(0, 0);
	if(GetButtonDown(0, LEFT)) delta.x--;
	if(GetButtonDown(0, RIGHT)) delta.x++;
	if(GetButtonDown(0, UP)) delta.y--;
	if(GetButtonDown(0, DOWN)) delta.y++;

	//Add the position delta to the position
	AddPosition(Vec3(delta, 0) * deltaTime * speed);

	//The character should only animate, if he is moving
	sprite.isPlaying = delta != VecI2(0);

	//If the character is moving to the right, flip the sprite 
	if(delta.x != 0) sprite.flipX = delta.x > 0;

	if(delta == VecI2(0, 0))
	{
		sprite.ResetAnimation();
	}
}