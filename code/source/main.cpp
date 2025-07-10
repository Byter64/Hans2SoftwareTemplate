#include <memory>
#include "Halib/Graphic.h"
#include "Halib/System.h"
#include "Character.h"
#include <iostream>

int main() 
{
	Halib::Init();
	//Create a player and add it to the system.
	//Entities will only be updated and drawn, when they have been added via AddEntity(...)
	std::shared_ptr<Character> player = std::make_shared<Character>(50.0f);
	Halib::AddEntity(player);

	//We have 5 Bits per color channel, so 31 is the max value
	Halib::rendersystem.backgroundColor = Halib::Color(15, 0, 24);
	while(!Halib::GetShouldClose()) 
	{
		Halib::rendersystem.backgroundColor.SetGreen((Halib::rendersystem.backgroundColor.GetGreen() + 1) % 32);
		
		//Normally, you don't need to touch this loop. Just let your classes inherit from Entity
		//to build your game (see Character.h)

		//This updates all halibs system, including inputs, graphics and entity logic
		//Take a look: Select Update() and press F12(?)
		Halib::Update();
	}
	
	return 0;
}
