#pragma once

#include <string>
#include <vector>
#include <cstdlib>
#include "Utilities/SingleDimensionArraysUtils.h"


class SnakeGame
{
public:
	enum class PlayingFieldPositionType : unsigned char
	{
		Empty = ' ',
		Border = '#',
		Shape = '*',
		Food = '@'
	};

private:
	bool _isGameEnded;
	int _foodsCollected;
	unsigned int _fieldWidth;
	unsigned int _fieldHeight;
	unsigned char* _oneDimensionPlayingField;
	Vector2 _headDirection{};
	std::vector<Vector2> _snakeBodyPositions;

	void InitializeEmptyField();

	[[nodiscard]] bool IsPositionInsideGameField(Vector2 position) const;

	bool CanHeadFitIn(Vector2 position);

	void PaintPointAs(Vector2 point, PlayingFieldPositionType type);

	void SpawnFoodAtRandomPoint();

	bool IsFoodPresentIn(Vector2 point);

public:
	SnakeGame(unsigned int fieldWidth, unsigned int fieldHeight);

	~SnakeGame();

	void SetHeadDirection(Vector2 direction);

	void Update();

	bool HasGameEnded() const;

	int GetCollectedFoodsCount() const;

	unsigned char* GetPlayingFieldBuffer();
};