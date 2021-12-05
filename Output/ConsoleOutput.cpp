#include "ConsoleOutput.h"


void ConsoleOutput::Print(unsigned char* buffer, unsigned int width, unsigned int height, int startPositionX, int startPositionY)
{
	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			bool doInsertNewLine = x == width - 1;
			int index = SingleDimensionArraysUtils::Get1dIndexFrom(x, y, width);

			std::cout << buffer[index];

			if (doInsertNewLine)
				std::cout << std::endl;
		}
	}
}
