#pragma once

#include "Vector2.h"

class SingleDimensionArraysUtils
{
public:
	static int GetRotated2dIndexAs1d(unsigned int xIndex, unsigned int yIndex, unsigned int widthOf2DArray,
			Vector2 normalizedDirection);

	static int Get1dIndexFrom(unsigned int xIndex, unsigned yIndex, unsigned int widthOf2DArray);
};