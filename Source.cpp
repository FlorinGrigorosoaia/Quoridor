
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Input and Output.h"



int main() 
{
	buildTexturesAndSprites();
	buildColors();
	initializeMovementArray( movementArray );
	buildButtons();
	buildTexts();
	buildRectangles();
	buildVerticalWalls();
	buildHorizontalWalls();

	startMenu();

	return 0;
}
