#include "SingleDimensionArraysUtils.h"

int SingleDimensionArraysUtils::GetRotated2dIndexAs1d(unsigned int x, unsigned int y, unsigned int width,
		Vector2 normalizedDirection)
{
	if (Vector2::Up == normalizedDirection)
		return y * width + x;
	else if (Vector2::Down == normalizedDirection)
		return (width * width) - 1 - width * y - x;
	else if (Vector2::Left == normalizedDirection)
		return width - 1 - y + width * x;
	else if (Vector2::Right == normalizedDirection)
		return width * (width - 1) + y - width * x;

	return 0;
}

int SingleDimensionArraysUtils::Get1dIndexFrom(unsigned int xIndex, unsigned yIndex, unsigned int WidthOf2DArray)
{
	return yIndex * WidthOf2DArray + xIndex;
}
