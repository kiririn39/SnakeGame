#include "Vector2.h"


bool Vector2::operator==(Vector2& other) const
{
	return other.X == this->X && other.Y == this->Y;
}

bool Vector2::operator!=(Vector2& other) const
{
	return !(this->operator==(other));
}

bool Vector2::IsOppositeTo(Vector2& other) const
{
	return other.X == -this->X && other.Y == -this->Y;
}

Vector2 Vector2::operator+(Vector2& other) const
{
	return { this->X + other.X, this->Y + other.Y };
}

Vector2 Vector2::operator-(Vector2& other) const
{
	return { this->X - other.X, this->Y - other.Y };
}

Vector2 Vector2::Normalized() const
{
	int x = this->X;
	int y = this->Y;

	if (x != 0)
		x /= x;

	if (y != 0)
		y /= y;

	return { x, y };
}

const Vector2 Vector2::Up(0, 1);

const Vector2 Vector2::Down(0, -1);

const Vector2 Vector2::Left(1, 0);
const Vector2 Vector2::Right(-1, 0);