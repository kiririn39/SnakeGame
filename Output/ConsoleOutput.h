#pragma once
#include <iostream>
#include "../Utilities/SingleDimensionArraysUtils.h"

class ConsoleOutput
{
public:
	static void Print(unsigned char* buffer, unsigned int width, unsigned int height, int startPositionX = 0, int startPositionY = 0);
};

