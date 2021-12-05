#pragma once

#include <conio.h>
#include <iostream>
#include "IInputActions.h"

class UserInput
{
private:
	const char UpKey = 'w';
	const char DownKey = 's';
	const char LeftKey = 'a';
	const char RightKey = 'd';
public:
	void InvokeInputOn(IInputActions& actions) const;
};