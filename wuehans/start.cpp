//What comes after start.s? Right, start.c
#include "Debug.h"
#include <Hall/Hall.h>
typedef void (*constructor_t)(void);

extern unsigned int _sbss;
extern unsigned int _ebss;

extern constructor_t __init_array_start[];
extern constructor_t __init_array_end[];
extern constructor_t __preinit_array_start[];
extern constructor_t __preinit_array_end[];

static void __init_data()
{
    for (unsigned int *data = &_sbss; data < &_ebss; data++) 
    {
        *data = 0;
    }
}

void __libc_init_array() 
{
	int count = __preinit_array_end - __preinit_array_start;
    for (int i = 0; i < count; i++) 
	{
        __preinit_array_start[i]();
    }

    count = __init_array_end - __init_array_start;
    for (int i = 0; i < count; i++) 
	{
        __init_array_start[i]();
    }
}

int main();

void _main()
{
    Hall::Clear(0b1111111111111111);
    while(Hall::GetIsGPUBusy());
    Hall::SetCommandSwapBuffers();

    Hall::Clear(0b1111111111111111);
    while(Hall::GetIsGPUBusy());
    Hall::SetCommandSwapBuffers();

    Hall::SetColorSource(Hall::MEMORY);

    Print("Ich wurde gestartet");
    __init_data();
	__libc_init_array();

    char buffer[64];

    Print("Jumping to main:");
	main();
    Print("Finished main?");

	while(1);
}