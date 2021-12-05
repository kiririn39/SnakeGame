#pragma once

#include <cstdint>

struct Vector2
{
	int X, Y;

	const static Vector2 Up;
	const static Vector2 Down;
	const static Vector2 Left;
	const static Vector2 Right;

	Vector2() = default;

	Vector2(int x, int y) : X(x), Y(y)
	{
	}

	explicit operator bool() = delete;

	bool operator==(Vector2& other) const;

	bool operator!=(Vector2& other) const;

	[[nodiscard]] Vector2 operator+(Vector2& other) const;

	[[nodiscard]] Vector2 operator-(Vector2& other) const;

	[[nodiscard]] Vector2 Normalized() const;

	[[nodiscard]] bool IsOppositeTo(Vector2& other) const;
};