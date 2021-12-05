#include "SnakeGame.h"


SnakeGame::SnakeGame(unsigned int fieldWidth, unsigned int fieldHeight)
{
	_isGameEnded = false;
	_foodsCollected = 0;
	_headDirection = Vector2::Up;
	this->_fieldHeight = fieldHeight;
	this->_fieldWidth = fieldWidth;
	_oneDimensionPlayingField = new unsigned char[fieldHeight * fieldWidth];

	InitializeEmptyField();
	SpawnFoodAtRandomPoint();
}

void SnakeGame::InitializeEmptyField()
{
	for (size_t x = 0; x < _fieldWidth; x++)
	{
		for (size_t y = 0; y < _fieldHeight; y++)
		{
			PlayingFieldPositionType type = PlayingFieldPositionType::Empty;
			Vector2 point(x, y);

			if (x == 0 || x == _fieldWidth - 1 || y == _fieldHeight - 1 || y == 0)
				type = PlayingFieldPositionType::Border;

			PaintPointAs(point, type);
		}
	}

	Vector2 fieldCenter((int)(_fieldWidth / 2), (int)(_fieldHeight / 2));

	PaintPointAs(fieldCenter, SnakeGame::PlayingFieldPositionType::Shape);
	_snakeBodyPositions.push_back(fieldCenter);
}

SnakeGame::~SnakeGame()
{
	delete (_oneDimensionPlayingField);
}

unsigned char* SnakeGame::GetPlayingFieldBuffer()
{
	return _oneDimensionPlayingField;
}

bool SnakeGame::IsPositionInsideGameField(Vector2 point) const
{
	return (point.X >= 0 && point.X < _fieldWidth) && (point.Y >= 0 && point.Y < _fieldHeight);
}

bool SnakeGame::CanHeadFitIn(Vector2 position)
{
	if (!IsPositionInsideGameField(position))
		return false;

	int fieldIndex = SingleDimensionArraysUtils::Get1dIndexFrom(position.X, position.Y, _fieldWidth);
	unsigned char positionType = _oneDimensionPlayingField[fieldIndex];

	if (positionType == (unsigned char)PlayingFieldPositionType::Border ||
		positionType == (unsigned char)PlayingFieldPositionType::Shape)
		return false;

	return true;
}

void SnakeGame::SetHeadDirection(Vector2 direction)
{
	if (_headDirection.IsOppositeTo(direction))
		return;

	_headDirection = direction;
}

void SnakeGame::Update()
{
	Vector2 nextHeadPosition = _snakeBodyPositions[0] + _headDirection;

	if (!CanHeadFitIn(nextHeadPosition) || _isGameEnded)
	{
		_isGameEnded = true;
		return;
	}

	bool hasFood = IsFoodPresentIn(nextHeadPosition);
	Vector2 previousTailPosition = _snakeBodyPositions.back();
	_snakeBodyPositions.emplace(_snakeBodyPositions.begin(), nextHeadPosition);

	PaintPointAs(nextHeadPosition, PlayingFieldPositionType::Shape);

	if (!hasFood)
	{
		_snakeBodyPositions.pop_back();
		PaintPointAs(previousTailPosition, PlayingFieldPositionType::Empty);
	}
	else
	{
		_foodsCollected++;
		SpawnFoodAtRandomPoint();
	}
}

void SnakeGame::PaintPointAs(Vector2 point, SnakeGame::PlayingFieldPositionType type)
{
	int index = SingleDimensionArraysUtils::Get1dIndexFrom(point.X, point.Y, _fieldWidth);

	_oneDimensionPlayingField[index] = (unsigned char)type;
}

void SnakeGame::SpawnFoodAtRandomPoint()
{
	bool foundAGoodSpot = false;
	Vector2 point;

	while (!foundAGoodSpot)
	{
		int x = rand() % _fieldWidth;
		int y = rand() % _fieldHeight;
		point.X = x;
		point.Y = y;

		if (CanHeadFitIn(point))
			foundAGoodSpot = true;
	}

	PaintPointAs(point, PlayingFieldPositionType::Food);
}

bool SnakeGame::IsFoodPresentIn(Vector2 point)
{
	int index = SingleDimensionArraysUtils::Get1dIndexFrom(point.X, point.Y, _fieldWidth);

	return _oneDimensionPlayingField[index] == (unsigned char)SnakeGame::PlayingFieldPositionType::Food;
}

bool SnakeGame::HasGameEnded() const
{
	return _isGameEnded;
}

int SnakeGame::GetCollectedFoodsCount() const
{
	return _foodsCollected;
}
