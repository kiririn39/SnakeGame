#include <iostream>
#include "Output/ConsoleOutput.h"
#include "SnakeGame.h"
#include "Input/ReversedSnakeGameInputActions.h"
#include "Input/UserInput.h"


int main()
{
	int width = 12;
	int height = 12;
	bool isGameOver = false;

	UserInput input;
	SnakeGame game(width, height);
	ReversedSnakeGameInputActions snakeActions(game);

	while (!isGameOver)
	{
		const unsigned char* buffer = game.GetPlayingFieldBuffer();

		ConsoleOutput::Print((unsigned char*)buffer, width, height);

		input.InvokeInputOn(snakeActions);

		game.Update();
		isGameOver = game.HasGameEnded();
	}

	std::cout << "Game ended. Your score is: " << game.GetCollectedFoodsCount();
	std::cin.get();
	return 0;
}