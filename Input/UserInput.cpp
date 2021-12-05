#include "UserInput.h"

void UserInput::InvokeInputOn(IInputActions& actions) const
{
	unsigned char input = getch();

	//std::cin >> input;

	if (input == UpKey)
		actions.Up();

	if (input == DownKey)
		actions.Down();

	if (input == LeftKey)
		actions.Left();

	if (input == RightKey)
		actions.Right();
}
