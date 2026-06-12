#pragma once
#include <memory>
#include <Hall/Hall.h>
#include <string>

struct Image
{
	short width; //Image width in pixels
	short height; //Image height in pixels
	std::shared_ptr<Hall::Color[]> data;

	Image() = default;
	Image(std::string path);
};