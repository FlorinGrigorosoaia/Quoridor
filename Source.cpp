
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Input and Output.h"



int main()
{
	buildColors();
	initializeMovementArray(movementArray);
	buildButtons();
	buildTexts();
	buildRectangles();
	buildVerticalWalls();
	buildHorizontalWalls();

	startMenu();

	return 0;
}
