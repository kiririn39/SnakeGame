#pragma once

#include "IInputActions.h"
#include "../SnakeGame.h"

class ReversedSnakeGameInputActions : public IInputActions
{
private:
	SnakeGame* _game;
public:
	explicit ReversedSnakeGameInputActions(SnakeGame& game);

	void Up() override;

	void Down() override;

	void Left() override;

	void Right() override;
};