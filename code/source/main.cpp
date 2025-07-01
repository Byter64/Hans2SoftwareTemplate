#include "Halib/Graphic.h"
#include "Halib/System.h"


int main() 
{
	Halib::Init();


	//This is your game loop. The program should never leave it.
	while(!Halib::GetShouldClose()) 
	{
		//Clear the screen. 
		//IMPORTANT: We have 5 bit per color channel, so the maximum value is 31
		//Alpha is either true (visible) or false (transparent)
		Halib::Clear(Halib::Color(15, 15, 0, true));

		//Show the changes that you made to the screen
		//This also blocks until the vsync 
		Halib::Show();
	}
	
	return 0;
}
