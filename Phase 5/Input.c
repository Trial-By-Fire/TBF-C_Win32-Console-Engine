// Parent Header
#include "Input.h"



// Includes
#include "Cycler.h"
#include "Memory.h"



// Static Data

// Private

BSS()

	InputData Input;

	char LastKeyPressed;



// Functions

// Public

fn returns(void) Input_LoadModule parameters(void)
{
	Input.LastPressedKey = '\0';
}

fn returns(Ptr(ro InputData)) GetInputContext(void)
{
	return getAddress(Input);
}

fn returns(Key) GetKeyPress parameters(void)
{
	return (Key)_getch();
}

fn returns(bool) KeyboardHit parameters(void)
{
	return (bool)_kbhit();
}

fn returns(void) ProcessInput parameters(void)
{
	if (KeyboardHit())
	{
		Input.LastPressedKey = GetKeyPress();
	}

	if (Input.LastPressedKey == 'q')
	{
		Cycler_Lapse();	
	}
}
