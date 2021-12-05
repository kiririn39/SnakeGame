#pragma once

class IInputActions
{
public:
	virtual void Up() = 0;

	virtual void Down() = 0;

	virtual void Left() = 0;

	virtual void Right() = 0;
};