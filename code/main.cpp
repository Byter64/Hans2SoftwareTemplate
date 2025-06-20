#include <Hall/Hall.h>


int main() 
{
	//This is your game loop. The program should never leave it.
	while(true) 
	{
		Hall::Clear(0b0100001000000001); 	//Clear the screen to R5G5B5A1(16, 16, 0, 1) or in RGBA8: (131, 131, 0, 255)
		while (Hall::GetIsGPUBusy());		//Wait for the GPU until it finished the last draw call


		bool vSync = false;
		bool newVSync = false;
		while(!(!vSync && newVSync)) 		//Wait until vSync == false and newVsync == true
		{									//Sidenote: This way of swapping the framebuffer vsyncs your game
			vSync = newVsync;
			newVSync = Hall::GetVSync();
		}
		
		Hall::SetCommandSwapBuffers();		//Swap the frame buffers so that your bewritten frame is shown

	}
	return 0;
}
