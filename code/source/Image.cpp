#include "Image.hpp"
#include "bmpread.h"
#include <iostream>

Image::Image(std::string path)
{
	bmpread_t bmp;
	int result = bmpread(path.c_str(), BMPREAD_TOP_DOWN | BMPREAD_ANY_SIZE | BMPREAD_ALPHA | BMPREAD_BYTE_ALIGN, &bmp);
	if (!result)
	{
		std::cerr << "COULD NOT LOAD ASSET \"" << path << "\". Idk why, though..." << std::endl;
	}
	std::shared_ptr<Hall::Color[]> data((Hall::Color *)bmp.data);

	this->data = data;
	width = bmp.width;
	height = bmp.height;
}