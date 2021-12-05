#include "ReversedSnakeGameInputActions.h"

ReversedSnakeGameInputActions::ReversedSnakeGameInputActions(SnakeGame& game)
{
	_game = &game;
}

void ReversedSnakeGameInputActions::Up()
{
	if (_game != nullptr)
		_game->SetHeadDirection(Vector2::Down);
}

void ReversedSnakeGameInputActions::Down()
{
	if (_game != nullptr)
		_game->SetHeadDirection(Vector2::Up);
}

void ReversedSnakeGameInputActions::Left()
{
	if (_game != nullptr)
		_game->SetHeadDirection(Vector2::Right);
}

void ReversedSnakeGameInputActions::Right()
{
	if (_game != nullptr)
		_game->SetHeadDirection(Vector2::Left);
}
