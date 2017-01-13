#pragma once
#include "Data Structures and Constants.h"
#include "Functions.h"


void printQuoridorInOneVsOne(sf::RectangleShape whatToPrint[10][10]);
void printQuoridorInFourPlayers(sf::RectangleShape whatToPrint[10][10]);
void printQuoridorInVsAI(sf::RectangleShape whatToPrint[10][10]);

void playOneVsOne();
void playVsAI();
void fourPlayers();

void buildTexturesAndSprites()
{
	backgroundTexture.loadFromFile( "q.jpg" );
	backgroundSprite.setTexture( backgroundTexture );
	float x = 1;
	float y = 1;
	backgroundSprite.setScale( x, y );

	x = 1;
	y = 1;

	oneVsOneTexture.loadFromFile( "q1.jpg" );
	oneVsOneSprite.setTexture( oneVsOneTexture );
	oneVsOneSprite.setScale( x, y );

	x = 0.6;
	y = 0.7;

	vsAITexture.loadFromFile( "q2.jpeg" );
	vsAISprite.setTexture( vsAITexture );
	vsAISprite.setScale( x, y );

	x = 0.8;
	y = 0.8;

	fourPlayersTexture.loadFromFile( "q3.jpg" );
	fourPlayersSprite.setTexture( fourPlayersTexture );
	fourPlayersSprite.setScale( x, y );
}

void buildColors()
{
	backgroundColor.r = 153;
	backgroundColor.g = 76;
	backgroundColor.b = 0;

	darkBrown.r = 51;
	darkBrown.g = 25;
	darkBrown.b = 0;

	Green.r = 0;
	Green.g = 153;
	Green.b = 0;

	brown.r = 112;
	brown.g = 79;
	brown.b = 21;

	lightGreen.r = 178;
	lightGreen.g = 255;
	lightGreen.b = 102;

	lightRed.r = 255;
	lightRed.g = 153;
	lightRed.b = 153;

	lightYellow.r = 255;
	lightYellow.g = 255;
	lightYellow.b = 153;

	purple.r = 102;
	purple.g = 0;
	purple.b = 102;
}

void buildTexts()
{
	font.loadFromFile("arial.ttf");

	oneVsOneText.setCharacterSize(FONT_SIZE);
	oneVsOneText.setStyle(sf::Text::Bold);
	oneVsOneText.setPosition(395, 100);
	oneVsOneText.setFillColor(sf::Color::White);

	vsAIText.setCharacterSize(FONT_SIZE);
	vsAIText.setStyle(sf::Text::Bold);
	vsAIText.setPosition(375, 270);
	vsAIText.setFillColor(sf::Color::White);

	fourPlayersText.setCharacterSize(FONT_SIZE);
	fourPlayersText.setStyle(sf::Text::Bold);
	fourPlayersText.setPosition(358, 440);
	fourPlayersText.setFillColor(sf::Color::White);

	detailsText.setCharacterSize(15);
	detailsText.setStyle(sf::Text::Italic);
	detailsText.setPosition(680, 600);

	goBackToStartMenuText.setCharacterSize(FONT_SIZE);
	goBackToStartMenuText.setStyle(sf::Text::Bold);
	goBackToStartMenuText.setPosition(703, 627);

	verticalButtonText.setCharacterSize(15);
	verticalButtonText.setStyle(sf::Text::Bold);
	verticalButtonText.setPosition(453, 115);

	horizontalButtonText.setCharacterSize(15);
	horizontalButtonText.setStyle(sf::Text::Bold);
	horizontalButtonText.setPosition(446, 215);

	firstPlayerNumberOfWallsLeft.setCharacterSize(15);
	firstPlayerNumberOfWallsLeft.setStyle(sf::Text::Bold);
	firstPlayerNumberOfWallsLeft.setPosition(650, 115);

	secondPlayerNumberOfWallsLeft.setCharacterSize(15);
	secondPlayerNumberOfWallsLeft.setStyle(sf::Text::Bold);
	secondPlayerNumberOfWallsLeft.setPosition(650, 215);

	thirdPlayerNumberOfWallsLeft.setCharacterSize(15);
	thirdPlayerNumberOfWallsLeft.setStyle(sf::Text::Bold);
	thirdPlayerNumberOfWallsLeft.setPosition(650, 315);

	fourthPlayerNumberOfWallsLeft.setCharacterSize(15);
	fourthPlayerNumberOfWallsLeft.setStyle(sf::Text::Bold);
	fourthPlayerNumberOfWallsLeft.setPosition(650, 415);

	AINumberOfWallsLeft.setCharacterSize(15);
	AINumberOfWallsLeft.setStyle(sf::Text::Bold);
	AINumberOfWallsLeft.setPosition(650, 115);

	firstPlayerWalls.setCharacterSize(15);
	firstPlayerWalls.setStyle(sf::Text::Bold);
	firstPlayerWalls.setPosition(725, 132);

	secondPlayerWalls.setCharacterSize(15);
	secondPlayerWalls.setStyle(sf::Text::Bold);
	secondPlayerWalls.setPosition(725, 232);

	thirdPlayerWalls.setCharacterSize(15);
	thirdPlayerWalls.setStyle(sf::Text::Bold);
	thirdPlayerWalls.setPosition(725, 332);

	fourthPlayerWalls.setCharacterSize(15);
	fourthPlayerWalls.setStyle(sf::Text::Bold);
	fourthPlayerWalls.setPosition(725, 432);

	AIWalls.setCharacterSize(15);
	AIWalls.setStyle(sf::Text::Bold);
	AIWalls.setPosition(725, 132);

	firstPlayerWon.setCharacterSize(40);
	firstPlayerWon.setStyle(sf::Text::Bold);
	firstPlayerWon.setPosition(300, 500);
	firstPlayerWon.setFillColor(sf::Color::Transparent);

	secondPlayerWon.setCharacterSize(40);
	secondPlayerWon.setStyle(sf::Text::Bold);
	secondPlayerWon.setPosition(300, 500);
	secondPlayerWon.setFillColor(sf::Color::Transparent);

	thirdPlayerWon.setCharacterSize(40);
	thirdPlayerWon.setStyle(sf::Text::Bold);
	thirdPlayerWon.setPosition(300, 500);
	thirdPlayerWon.setFillColor(sf::Color::Transparent);

	fourthPlayerWon.setCharacterSize(40);
	fourthPlayerWon.setStyle(sf::Text::Bold);
	fourthPlayerWon.setPosition(300, 500);
	fourthPlayerWon.setFillColor(sf::Color::Transparent);

	AIWon.setCharacterSize(40);
	AIWon.setStyle(sf::Text::Bold);
	AIWon.setPosition(300, 500);
	AIWon.setFillColor(sf::Color::Transparent);
}

void buildButtons()
{
	oneVsOneButton.setSize(sf::Vector2f(DIM_OF_BUTTON_OX, DIM_OF_BUTTON_OY));
	oneVsOneButton.setPosition(335, 50);
	oneVsOneButton.setFillColor( backgroundColor );

	vsAIButton.setSize(sf::Vector2f(DIM_OF_BUTTON_OX, DIM_OF_BUTTON_OY));
	vsAIButton.setPosition(335, 220);
	vsAIButton.setFillColor( backgroundColor );

	fourPlayersButton.setSize(sf::Vector2f(DIM_OF_BUTTON_OX, DIM_OF_BUTTON_OY));
	fourPlayersButton.setPosition(335, 390);
	fourPlayersButton.setFillColor( backgroundColor );

	goBackToStartMenuButton.setSize(sf::Vector2f(150, 80));
	goBackToStartMenuButton.setPosition(650, 600);
	goBackToStartMenuButton.setFillColor( backgroundColor );

	verticalButton.setSize(sf::Vector2f(200, 70));
	verticalButton.setPosition(400, 100);
	verticalButton.setFillColor( darkBrown );

	horizontalButton.setSize(sf::Vector2f(200, 70));
	horizontalButton.setPosition(400, 200);
	horizontalButton.setFillColor( darkBrown );
}

void printStartMenu()
{
	window.draw( backgroundSprite );

	window.draw(oneVsOneButton);
	window.draw(vsAIButton);
	window.draw(fourPlayersButton);

	window.draw(oneVsOneText);
	window.draw(vsAIText);
	window.draw(fourPlayersText);
	window.draw(detailsText);
}

void buildVerticalWalls()
{
	int axaX = 37;
	int axaY = 10;
	int adder = 40;

	for (int i = 0; i < 8; i++)
	{
		verticalWalls[i][0].setPosition(axaX, axaY);
		verticalWalls[i][0].setSize(sf::Vector2f(15, 65));
		verticalWalls[i][0].setFillColor(sf::Color::Transparent);
		for (int j = 1; j < 8; j++)
		{
			axaX += adder;
			verticalWalls[i][j].setSize(sf::Vector2f(15, 65));
			verticalWalls[i][j].setPosition(axaX, axaY);
			verticalWalls[i][j].setFillColor(sf::Color::Transparent);
		}
		axaY += adder;
		axaX = 37;
	}
}

void buildHorizontalWalls()
{
	int axaX = 12;
	int axaY = 35;
	int adder = 40;

	for (int i = 0; i < 8; i++)
	{
		horizontalWalls[i][0].setPosition(axaX, axaY);
		horizontalWalls[i][0].setSize(sf::Vector2f(65, 15));
		horizontalWalls[ i ][ 0 ].setFillColor( sf::Color::Transparent );
		for (int j = 1; j < 8; j++)
		{
			axaX += adder;
			horizontalWalls[i][j].setSize(sf::Vector2f(65, 15));
			horizontalWalls[i][j].setPosition(axaX, axaY);
			horizontalWalls[i][j].setFillColor(sf::Color::Transparent);
		}
		axaY += adder;
		axaX = 12;
	}
}

void buildRectangles()
{
	int axaY = 10;
	int axaX = 12;
	int adder = 40;

	for (int i = 0; i < 9; i++)
	{
		rectangles[i][0].setPosition(axaX, axaY);
		rectangles[i][0].setSize(sf::Vector2f(SQUARE_SIDE, SQUARE_SIDE));
		rectangles[i][0].setFillColor(sf::Color::White);
		for (int j = 1; j < 9; j++)
		{
			axaX += adder;
			rectangles[i][j].setSize(sf::Vector2f(SQUARE_SIDE, SQUARE_SIDE));
			rectangles[i][j].setPosition(axaX, axaY);
			rectangles[i][j].setFillColor(sf::Color::White);
		}
		axaY += adder;
		axaX = 12;
	}
}

void initializeRectangles()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			rectangles[i][j].setFillColor(sf::Color::White);
}

void initializeWonText()
{
	firstPlayerWon.setFillColor(sf::Color::Transparent);
	secondPlayerWon.setFillColor(sf::Color::Transparent);
	thirdPlayerWon.setFillColor(sf::Color::Transparent);
	fourthPlayerWon.setFillColor(sf::Color::Transparent);
	AIWon.setFillColor(sf::Color::Transparent);

}

void initializeWalls()
{
	for (int i = 0; i<8; i++)
		for (int j = 0; j<8; j++)
		{
			verticalWalls[i][j].setFillColor(sf::Color::Transparent);
			horizontalWalls[i][j].setFillColor(sf::Color::Transparent);
		}
}

void startMenu()
{
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i mouse = sf::Mouse::getPosition(window);
				if ((mouse.x >= 335) && (mouse.x <= 335 + DIM_OF_BUTTON_OX) && (mouse.y >= 50) && (mouse.y <= 50 + DIM_OF_BUTTON_OY))
					playOneVsOne();
				else if ((mouse.x >= 335) && (mouse.x <= 335 + DIM_OF_BUTTON_OX) && (mouse.y >= 390) && (mouse.y <= 390 + DIM_OF_BUTTON_OY))
					fourPlayers();
				else if ((mouse.x >= 335) && (mouse.x <= 335 + DIM_OF_BUTTON_OX) && (mouse.y >= 220) && (mouse.y <= 220 + DIM_OF_BUTTON_OY))
					playVsAI();
			}
		}

		window.clear();
		printStartMenu();
		window.display();
	}
}

void printQuoridorInOneVsOne(sf::RectangleShape whatToPrint[10][10])
{
	window.draw( oneVsOneSprite );

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			window.draw(whatToPrint[i][j]);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			window.draw(verticalWalls[i][j]);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			window.draw(horizontalWalls[i][j]);

	window.draw(goBackToStartMenuButton);
	window.draw(goBackToStartMenuText);
	window.draw(verticalButton);
	window.draw(horizontalButton);
	window.draw(verticalButtonText);
	window.draw(horizontalButtonText);

	window.draw(firstPlayerNumberOfWallsLeft);
	window.draw(secondPlayerNumberOfWallsLeft);

	window.draw(firstPlayerWalls);
	window.draw(secondPlayerWalls);

	window.draw(firstPlayerWon);
	window.draw(secondPlayerWon);
}

void printQuoridorInFourPlayers(sf::RectangleShape whatToPrint[10][10])
{
	window.draw( fourPlayersSprite );

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			window.draw(whatToPrint[i][j]);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			window.draw(verticalWalls[i][j]);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			window.draw(horizontalWalls[i][j]);

	window.draw(goBackToStartMenuButton);
	window.draw(goBackToStartMenuText);
	window.draw(verticalButton);
	window.draw(horizontalButton);
	window.draw(verticalButtonText);
	window.draw(horizontalButtonText);

	window.draw(firstPlayerNumberOfWallsLeft);
	window.draw(secondPlayerNumberOfWallsLeft);
	window.draw(thirdPlayerNumberOfWallsLeft);
	window.draw(fourthPlayerNumberOfWallsLeft);

	window.draw(firstPlayerWalls);
	window.draw(secondPlayerWalls);
	window.draw(thirdPlayerWalls);
	window.draw(fourthPlayerWalls);

	window.draw(firstPlayerWon);
	window.draw(secondPlayerWon);
	window.draw(thirdPlayerWon);
	window.draw(fourthPlayerWon);
}

void printQuoridorInVsAI(sf::RectangleShape whatToPrint[10][10])
{
	window.draw( vsAISprite );

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			window.draw(whatToPrint[i][j]);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			window.draw(verticalWalls[i][j]);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			window.draw(horizontalWalls[i][j]);

	window.draw(goBackToStartMenuButton);
	window.draw(goBackToStartMenuText);
	window.draw(verticalButton);
	window.draw(horizontalButton);
	window.draw(verticalButtonText);
	window.draw(horizontalButtonText);

	window.draw(AINumberOfWallsLeft);
	window.draw(secondPlayerNumberOfWallsLeft);

	window.draw(AIWalls);
	window.draw(secondPlayerWalls);

	window.draw(AIWon);
	window.draw(secondPlayerWon);
}

void playOneVsOne()
{
	initializeRectangles();
	initializeWonText();
	initializeWalls();
	bool buttonForWallPressed = false;
	matrixPosition verticalWallPosition;
	matrixPosition horizontalWallPosition;
	bool switchPlayers = true; 
	setBorder(quoridorMatrix);
	setNeededDataOneVsOne(quoridorMatrix, switchPlayers);
	firstPlayerWalls.setString(std::to_string(firstPlayer.numberOfWallsLeft));
	secondPlayerWalls.setString(std::to_string(secondPlayer.numberOfWallsLeft));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			copyTwoRectangles(shadows, rectangles);

			if (switchPlayers == true)
			{
				for (int i = 0; i <= 3; i++)
				{
					int newLine = firstPlayer.position.line + movementArray[i].line;
					int newColumn = firstPlayer.position.column + movementArray[i].column;

					if (quoridorMatrix[newLine][newColumn] == 0)
					{
						newLine += movementArray[i].line;
						newColumn += movementArray[i].column;

						if (quoridorMatrix[newLine][newColumn] == 0)
							shadows[(newLine - 1) / 2][(newColumn - 1) / 2].setFillColor(lightRed);
						else
						{
							newLine += movementArray[i].line;
							newColumn += movementArray[i].column;

							if (quoridorMatrix[newLine][newColumn] == 0)
							{
								newLine += movementArray[i].line;
								newColumn += movementArray[i].column;

								shadows[(newLine - 1) / 2][(newColumn - 1) / 2].setFillColor(lightRed);
							}
							else
							{
								newLine -= movementArray[i].line;
								newColumn -= movementArray[i].column;

								if ((i == 0) || (i == 2))
								{
									for (int j = 1; j <= 3; j += 2)
									{
										int nextLine = newLine + movementArray[j].line;
										int nextColumn = newColumn + movementArray[j].column;

										if (quoridorMatrix[nextLine][nextColumn] == 0)
										{
											nextLine += movementArray[j].line;
											nextColumn += movementArray[j].column;

											shadows[(nextLine - 1) / 2][(nextColumn - 1) / 2].setFillColor(lightRed);
										}
									}
								}
								else
								{
									for (int j = 0; j <= 2; j += 2)
									{
										int nextLine = newLine + movementArray[j].line;
										int nextColumn = newColumn + movementArray[j].column;

										if (quoridorMatrix[newLine][newColumn] == 0)
										{
											nextLine += movementArray[j].line;
											nextColumn += movementArray[j].column;

											shadows[(nextLine - 1) / 2][(nextColumn - 1) / 2].setFillColor(lightRed);
										}
									}
								}
							}
						}
					}
				}
			}
			else
			{
				for (int i = 0; i <= 3; i++)
				{
					int newLine = secondPlayer.position.line + movementArray[i].line;
					int newColumn = secondPlayer.position.column + movementArray[i].column;
					if (quoridorMatrix[newLine][newColumn] == 0)
					{
						newLine += movementArray[i].line;
						newColumn += movementArray[i].column;

						if (quoridorMatrix[newLine][newColumn] == 0)
							shadows[(newLine - 1) / 2][(newColumn - 1) / 2].setFillColor(lightGreen);
						else
						{
							newLine += movementArray[i].line;
							newColumn += movementArray[i].column;

							if (quoridorMatrix[newLine][newColumn] == 0)
							{
								newLine += movementArray[i].line;
								newColumn += movementArray[i].column;

								shadows[(newLine - 1) / 2][(newColumn - 1) / 2].setFillColor(lightGreen);
							}
							else
							{
								newLine -= movementArray[i].line;
								newColumn -= movementArray[i].column;

								if ((i == 0) || (i == 2))
								{
									for (int j = 1; j <= 3; j += 2)
									{
										int nextLine = newLine + movementArray[j].line;
										int nextColumn = newColumn + movementArray[j].column;

										if (quoridorMatrix[nextLine][nextColumn] == 0)
										{
											nextLine += movementArray[j].line;
											nextColumn += movementArray[j].column;

											shadows[(nextLine - 1) / 2][(nextColumn - 1) / 2].setFillColor(lightGreen);
										}
									}
								}
								else
								{
									for (int j = 0; j <= 2; j += 2)
									{
										int nextLine = newLine + movementArray[j].line;
										int nextColumn = newColumn + movementArray[j].column;

										if (quoridorMatrix[nextLine][nextColumn] == 0)
										{
											nextLine += movementArray[j].line;
											nextColumn += movementArray[j].column;

											shadows[(nextLine - 1) / 2][(nextColumn - 1) / 2].setFillColor(lightGreen);
										}
									}
								}
							}
						}
					}
				}
			}

			window.clear();
			printQuoridorInOneVsOne(shadows);
			window.display();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i mouse = sf::Mouse::getPosition(window);
				int x = mouse.x;
				int y = mouse.y;

				if (buttonForWallPressed)
				{
					if (switchPlayers == true)
					{
						// before assignWall should check if the wall position is correct ( lee )
						if ((x >= 400) && (x <= 600) && (y >= 100) && (y <= 170)) // vertical
						{
							int leeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];
							int newLeeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];
							copyTwoMatrices(quoridorMatrix, leeMatrix);
							copyTwoMatrices(quoridorMatrix, newLeeMatrix);
							assignWall(leeMatrix, verticalWallPosition, 'v', 1);
							assignWall(newLeeMatrix, verticalWallPosition, 'v', 1);

							if ( ( firstPlayer.numberOfWallsLeft > 0 ) && ( leeOnLine( leeMatrix, secondPlayer, 1 ) ) && ( leeOnLine( newLeeMatrix, firstPlayer, 17 ) ) )
							{
								if ( (quoridorMatrix[verticalWallPosition.line][verticalWallPosition.column] == 0) && ( quoridorMatrix[ verticalWallPosition.line + 1 ][ verticalWallPosition.column ] == 0 ) && ( quoridorMatrix[ verticalWallPosition.line + 2 ][ verticalWallPosition.column ] == 0 ) )
								{
									assignWall( quoridorMatrix, verticalWallPosition, 'v', 0 );
									firstPlayer.numberOfWallsLeft--;
									firstPlayerWalls.setString( std::to_string( firstPlayer.numberOfWallsLeft ) );
									switchPlayers = false;
								}
							}
						}
						if ((x >= 400) && (x <= 600) && (y >= 200) && (y <= 270)) // horizontal
						{
							int leeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];
							int newLeeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];
							copyTwoMatrices(quoridorMatrix, leeMatrix);
							copyTwoMatrices(quoridorMatrix, newLeeMatrix);
							assignWall(leeMatrix, horizontalWallPosition, 'h', 1);
							assignWall(newLeeMatrix, horizontalWallPosition, 'v', 1);

							if ((firstPlayer.numberOfWallsLeft > 0) && (leeOnLine(leeMatrix, secondPlayer, 1)) && (leeOnLine(newLeeMatrix, firstPlayer, 17)))
							{
								if ( ( quoridorMatrix[ horizontalWallPosition.line ][ horizontalWallPosition.column ] == 0 ) && ( quoridorMatrix[ horizontalWallPosition.line ][ horizontalWallPosition.column + 1 ] == 0 ) && ( quoridorMatrix[ horizontalWallPosition.line ][ horizontalWallPosition.column + 2 ] == 0 ) )
								{
									assignWall( quoridorMatrix, horizontalWallPosition, 'h', 0 );
									firstPlayer.numberOfWallsLeft--;
									firstPlayerWalls.setString( std::to_string( firstPlayer.numberOfWallsLeft ) );
									switchPlayers = false;
								}
							}
						}
						buttonForWallPressed = false;
						verticalButton.setFillColor(darkBrown);
						horizontalButton.setFillColor( darkBrown );
					}
					else
					{
						// before assignWall should check if the wall position is correct ( lee )
						if ((x >= 400) && (x <= 600) && (y >= 100) && (y <= 170)) // vertical
						{
							int leeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];
							int newLeeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];
							copyTwoMatrices(quoridorMatrix, leeMatrix);
							copyTwoMatrices(quoridorMatrix, newLeeMatrix);
							assignWall(leeMatrix, verticalWallPosition, 'v', 1);
							assignWall(newLeeMatrix, verticalWallPosition, 'v', 1);

							if ((secondPlayer.numberOfWallsLeft > 0) && (leeOnLine(leeMatrix, firstPlayer, 17)) && (leeOnLine(newLeeMatrix, secondPlayer, 1)))
							{
								if ( ( quoridorMatrix[ verticalWallPosition.line ][ verticalWallPosition.column ] == 0 ) && ( quoridorMatrix[ verticalWallPosition.line + 1 ][ verticalWallPosition.column ] == 0 ) && ( quoridorMatrix[ verticalWallPosition.line + 2 ][ verticalWallPosition.column ] == 0 ) )
								{
									assignWall( quoridorMatrix, verticalWallPosition, 'v', 0 );
									secondPlayer.numberOfWallsLeft--;
									secondPlayerWalls.setString( std::to_string( secondPlayer.numberOfWallsLeft ) );
									switchPlayers = true;
								}
							}
						}
						if ((x >= 400) && (x <= 600) && (y >= 200) && (y <= 270)) // horizontal
						{
							int leeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];
							int newLeeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];
							copyTwoMatrices(quoridorMatrix, leeMatrix);
							copyTwoMatrices(quoridorMatrix, newLeeMatrix);
							assignWall(leeMatrix, horizontalWallPosition, 'h', 1);
							assignWall(newLeeMatrix, horizontalWallPosition, 'v', 1);

							if ((secondPlayer.numberOfWallsLeft > 0) && (leeOnLine(leeMatrix, firstPlayer, 17)) && (leeOnLine(newLeeMatrix, secondPlayer, 1)))
							{
								if ( ( quoridorMatrix[ horizontalWallPosition.line ][ horizontalWallPosition.column ] == 0 ) && ( quoridorMatrix[ horizontalWallPosition.line ][ horizontalWallPosition.column + 1 ] == 0 ) && ( quoridorMatrix[ horizontalWallPosition.line ][ horizontalWallPosition.column + 2 ] == 0 ) )
								{
									assignWall( quoridorMatrix, horizontalWallPosition, 'h', 0 );
									secondPlayer.numberOfWallsLeft--;
									secondPlayerWalls.setString( std::to_string( secondPlayer.numberOfWallsLeft ) );
									switchPlayers = true;
								}
							}
						}
						buttonForWallPressed = false;
						verticalButton.setFillColor( darkBrown );
						horizontalButton.setFillColor( darkBrown );
					}
				}

				if (x >= 12 && x <= (15 + 25) * 9 + 12 && y >= 10 && y <= (15 + 25) * 9 + 10)
				{
					int j = (x - 12) / (25 + 15);
					int i = (y - 10) / (25 + 15);

					int offsetX = j * (25 + 15) + 12;
					int offsetY = i * (25 + 15) + 10;

					if (x > offsetX + 0 && x < offsetX + 25 && y > offsetY + 0 && y < offsetY + 25)
					{
						// apelez ca vrea sa mute pionul
						if (switchPlayers == true)
						{
							if ( shadows[ i ][ j ].getFillColor() == lightRed )
							{
								movePawn( quoridorMatrix, firstPlayer, switchPlayers, 2 * i + 1, 2 * j + 1, false );
								switchPlayers = false;
							}
						}
						else
						{
							if ( shadows[ i ][ j ].getFillColor() == lightGreen )
							{
								movePawn( quoridorMatrix, secondPlayer, switchPlayers, 2 * i + 1, 2 * j + 1, false );
								switchPlayers = true;
							}
						}
					}
					if (x > offsetX + 25 && x < offsetX + 25 + 15 && y > offsetY + 25 && y < offsetY + 25 + 15)
					{
						verticalWallPosition.line = 2 * i + 1;
						verticalWallPosition.column = 2 * j + 2;
						horizontalWallPosition.line = 2 * i + 2;
						horizontalWallPosition.column = 2 * j + 1;
						buttonForWallPressed = true;
						verticalButton.setFillColor(brown);
						horizontalButton.setFillColor(brown);
					}
				}
				else if ((x >= 650) && (y >= 600) && (x <= 800) && (y <= 680)) // go back
					startMenu();
			}
			if (firstPlayer.position.line == 17)
				firstPlayerWon.setFillColor(sf::Color::Red);
			if (secondPlayer.position.line == 1)
				secondPlayerWon.setFillColor(Green);
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}

void sendToAssignWallWithDirection(int &whichPlayer, int x, int y, matrixPosition wallPosition, char direction)
{
	int firstLeeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];
	int secondLeeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];
	int thirdLeeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];
	int fourthLeeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];

	copyTwoMatrices(quoridorMatrix, firstLeeMatrix);
	copyTwoMatrices(quoridorMatrix, secondLeeMatrix);
	copyTwoMatrices(quoridorMatrix, thirdLeeMatrix);
	copyTwoMatrices(quoridorMatrix, fourthLeeMatrix);

	assignWall(firstLeeMatrix, wallPosition, direction, 1);
	assignWall(firstLeeMatrix, wallPosition, direction, 1);
	assignWall(firstLeeMatrix, wallPosition, direction, 1);
	assignWall(firstLeeMatrix, wallPosition, direction, 1);

	if ((leeOnLine(firstLeeMatrix, firstPlayer, 17)) && (leeOnLine(secondLeeMatrix, secondPlayer, 1)) && (leeOnColumn(thirdLeeMatrix, thirdPlayer, 17)) && (leeOnColumn(fourthLeeMatrix, fourthPlayer, 1)))
	{
		if (whichPlayer == 1)
		{
			assignWall(quoridorMatrix, wallPosition, direction, 0);
			firstPlayer.numberOfWallsLeft--;
			firstPlayerWalls.setString(std::to_string(firstPlayer.numberOfWallsLeft));
			whichPlayer++;
		}
		else if (whichPlayer == 0)
		{
			assignWall(quoridorMatrix, wallPosition, direction, 0);
			secondPlayer.numberOfWallsLeft--;
			secondPlayerWalls.setString(std::to_string(secondPlayer.numberOfWallsLeft));
			whichPlayer++;
		}
		else if (whichPlayer == 2)
		{
			assignWall(quoridorMatrix, wallPosition, direction, 0);
			thirdPlayer.numberOfWallsLeft--;
			thirdPlayerWalls.setString(std::to_string(thirdPlayer.numberOfWallsLeft));
			whichPlayer++;
		}
		else
		{
			assignWall(quoridorMatrix, wallPosition, direction, 0);
			fourthPlayer.numberOfWallsLeft--;
			fourthPlayerWalls.setString(std::to_string(fourthPlayer.numberOfWallsLeft));
			whichPlayer = 0;
		}
	}
}

void sendToAssignWall(int &whichPlayer, int x, int y, matrixPosition verticalWallPosition, matrixPosition horizontalWallPosition)
{
	if ((x >= 400) && (x <= 600) && (y >= 100) && (y <= 170)) // vertical
		if ( ( quoridorMatrix[ verticalWallPosition.line ][ verticalWallPosition.column ] == 0 ) && ( quoridorMatrix[ verticalWallPosition.line + 1 ][ verticalWallPosition.column ] == 0 ) && ( quoridorMatrix[ verticalWallPosition.line + 2 ][ verticalWallPosition.column ] == 0 ) )
			sendToAssignWallWithDirection(whichPlayer, x, y, verticalWallPosition, 'v');

	if ((x >= 400) && (x <= 600) && (y >= 200) && (y <= 270)) // horizontal
		if ( ( quoridorMatrix[ horizontalWallPosition.line ][ horizontalWallPosition.column ] == 0 ) && ( quoridorMatrix[ horizontalWallPosition.line ][ horizontalWallPosition.column + 1 ] == 0 ) && ( quoridorMatrix[ horizontalWallPosition.line ][ horizontalWallPosition.column + 2 ] == 0 ) )
			sendToAssignWallWithDirection(whichPlayer, x, y, horizontalWallPosition, 'h');
}

void sendToMovePawn(int &whichPlayer, int i, int j)
{
	if (whichPlayer % 4 == 1)
	{
		if ( shadows[ i ][ j ].getFillColor() == lightRed )
		{
			movePawn(quoridorMatrix, firstPlayer, whichPlayer, 2 * i + 1, 2 * j + 1, false);
			whichPlayer++;
		}
		
	}
	else if (whichPlayer % 4 == 0)
	{
		if ( shadows[ i ][ j ].getFillColor() == lightGreen )
		{
			movePawn(quoridorMatrix, secondPlayer, whichPlayer, 2 * i + 1, 2 * j + 1, false);
			whichPlayer++;
		}

	}
	else if (whichPlayer % 4 == 2)
	{
		if ( shadows[ i ][ j ].getFillColor() == lightYellow )
		{
			movePawn(quoridorMatrix, thirdPlayer, whichPlayer, 2 * i + 1, 2 * j + 1, false);
			whichPlayer++;
		}

	}
	else
	{
		if ( shadows[ i ][ j ].getFillColor() == sf::Color::Cyan )
		{
			movePawn(quoridorMatrix, fourthPlayer, whichPlayer, 2 * i + 1, 2 * j + 1, false);
			whichPlayer = 0;
		}

	}
}

void findFartherNeighbours( player currentPlayer, sf::Color currentColor, int indexInMovementArray, int currentLine, int currentColumn )
{
	int newLine = currentLine + movementArray[indexInMovementArray].line;
	int newColumn = currentColumn + movementArray[indexInMovementArray].column;

	if ( quoridorMatrix[newLine][newColumn] == 0 ) // there is no wall
	{
		newLine += movementArray[indexInMovementArray].line;
		newColumn += movementArray[indexInMovementArray].column;

		if (quoridorMatrix[newLine][newColumn] == 0) // there is no pawn
			shadows[(newLine - 1) / 2][(newColumn - 1) / 2].setFillColor(currentColor);
		else // there is pawn
			findFartherNeighbours(currentPlayer, currentColor, indexInMovementArray, newLine, newColumn);
	}
	else // there is wall
	{
		newLine -= movementArray[indexInMovementArray].line;
		newColumn -= movementArray[indexInMovementArray].column;

		if ((indexInMovementArray == 0) || (indexInMovementArray == 2)) // up or down
		{
			for (int j = 1; j <= 3; j += 2)
			{
				int nextLine = newLine + movementArray[j].line;
				int nextColumn = newColumn + movementArray[j].column;

				if (quoridorMatrix[nextLine][nextColumn] == 0) // there is no wall
				{
					nextLine = newLine + movementArray[j].line;
					nextColumn = newColumn + movementArray[j].column;

					if (quoridorMatrix[nextLine][nextColumn] == 0) // there is no pawn
						shadows[(nextLine - 1) / 2][(nextColumn - 1) / 2].setFillColor(currentColor);
				}
			}
		}
		if ((indexInMovementArray == 1) || (indexInMovementArray == 3))
		{
			for ( int j = 0; j <= 2; j += 2) 
			{
				int nextLine = newLine + movementArray[j].line;
				int nextColumn = newColumn + movementArray[j].column;

				if (quoridorMatrix[nextLine][nextColumn] == 0) // there is no wall
				{
					nextLine += movementArray[j].line;
					nextColumn += movementArray[j].column;

					if (quoridorMatrix[nextLine][nextColumn] == 0) // there is no pawn
						shadows[(nextLine - 1) / 2][(nextColumn - 1) / 2].setFillColor(currentColor);
				}
			}
		}
	}
}

void findNeighbours( player currentPlayer, sf::Color currentColor )
{
	for ( int i = 0; i <= 3; i++ )
	{
		int newLine = currentPlayer.position.line + movementArray[ i ].line;
		int newColumn = currentPlayer.position.column + movementArray[ i ].column;

		if ( quoridorMatrix[ newLine ][ newColumn ] == 0 ) // there is no wall
		{
			newLine += movementArray[i].line;
			newColumn += movementArray[i].column;

			if (quoridorMatrix[newLine][newColumn] == 0) // there is no pawn
				shadows[(newLine - 1) / 2][(newColumn - 1) / 2].setFillColor(currentColor);
			else // there is pawn
				findFartherNeighbours(currentPlayer, currentColor, i, newLine, newColumn );
		}
	}
}

void setShadows(int whichPlayer)
{
	if (whichPlayer == 1)
		findNeighbours(firstPlayer, lightRed);
	else if (whichPlayer == 0)
		findNeighbours(secondPlayer, lightGreen);
	else if (whichPlayer == 2)
		findNeighbours(thirdPlayer, lightYellow);
	else if (whichPlayer == 3)
		findNeighbours(fourthPlayer, sf::Color::Cyan);

	
}

void fourPlayers()
{
	initializeRectangles();
	initializeWonText();
	initializeWalls();

	bool buttonForWallPressed = false;
	matrixPosition verticalWallPosition;
	matrixPosition horizontalWallPosition;
	int switchPlayers = 0;

	setBorder(quoridorMatrix);
	setNeededDataFourPlayers(quoridorMatrix, switchPlayers);

	firstPlayerWalls.setString(std::to_string(firstPlayer.numberOfWallsLeft));
	secondPlayerWalls.setString(std::to_string(secondPlayer.numberOfWallsLeft));
	thirdPlayerWalls.setString(std::to_string(thirdPlayer.numberOfWallsLeft));
	fourthPlayerWalls.setString(std::to_string(fourthPlayer.numberOfWallsLeft));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			copyTwoRectangles(shadows, rectangles);

			setShadows(switchPlayers);
			window.clear();
			printQuoridorInFourPlayers(shadows);
			window.display();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i mouse = sf::Mouse::getPosition(window);
				int x = mouse.x;
				int y = mouse.y;

				if (buttonForWallPressed)
				{
					sendToAssignWall(switchPlayers, x, y, verticalWallPosition, horizontalWallPosition);
					buttonForWallPressed = false;
					verticalButton.setFillColor( darkBrown );
					horizontalButton.setFillColor( darkBrown );
				}

				if (x >= 12 && x <= (15 + 25) * 9 + 12 && y >= 10 && y <= (15 + 25) * 9 + 10)
				{
					int j = (x - 12) / (25 + 15);
					int i = (y - 10) / (25 + 15);

					int offsetX = j * (25 + 15) + 12;
					int offsetY = i * (25 + 15) + 10;

					if (x > offsetX + 0 && x < offsetX + 25 && y > offsetY + 0 && y < offsetY + 25)
					{
						sendToMovePawn(switchPlayers, i, j);
					}
					if (x > offsetX + 25 && x < offsetX + 25 + 15 && y > offsetY + 25 && y < offsetY + 25 + 15)
					{
						verticalWallPosition.line = 2 * i + 1;
						verticalWallPosition.column = 2 * j + 2;
						horizontalWallPosition.line = 2 * i + 2;
						horizontalWallPosition.column = 2 * j + 1;

						buttonForWallPressed = true;
						verticalButton.setFillColor(brown);
						horizontalButton.setFillColor(brown);
					}
				}
				else if ((x >= 650) && (y >= 600) && (x <= 800) && (y <= 680)) // go back
					startMenu();
			}

			if (firstPlayer.position.line == 17)
				firstPlayerWon.setFillColor(sf::Color::Red);
			if (secondPlayer.position.line == 1)
				secondPlayerWon.setFillColor(Green);
			if (thirdPlayer.position.column == 17)
				thirdPlayerWon.setFillColor(sf::Color::Yellow);
			if (fourthPlayer.position.column == 1)
				fourthPlayerWon.setFillColor(sf::Color::Blue);
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}

void playVsAI()
{
	initializeRectangles();
	initializeWonText();
	initializeWalls();

	bool buttonForWallPressed = false;
	matrixPosition verticalWallPosition;
	matrixPosition horizontalWallPosition;
	bool switchPlayers = false;
	setBorder(quoridorMatrix);
	setNeededDataVsAI(quoridorMatrix, switchPlayers);
	secondPlayerWalls.setString(std::to_string(secondPlayer.numberOfWallsLeft));
	AIWalls.setString(std::to_string(AI.numberOfWallsLeft));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			copyTwoRectangles(shadows, rectangles);

			if (switchPlayers == false)
			{
				for (int i = 0; i <= 3; i++)
				{
					int newLine = secondPlayer.position.line + movementArray[i].line;
					int newColumn = secondPlayer.position.column + movementArray[i].column;

					if (quoridorMatrix[newLine][newColumn] == 0)
					{
						newLine += movementArray[i].line;
						newColumn += movementArray[i].column;

						if (quoridorMatrix[newLine][newColumn] == 0)
							shadows[(newLine - 1) / 2][(newColumn - 1) / 2].setFillColor(lightGreen);
						else
						{
							newLine += movementArray[i].line;
							newColumn += movementArray[i].column;

							if (quoridorMatrix[newLine][newColumn] == 0)
							{
								newLine += movementArray[i].line;
								newColumn += movementArray[i].column;

								shadows[(newLine - 1) / 2][(newColumn - 1) / 2].setFillColor(lightGreen);
							}
							else
							{
								newLine -= movementArray[i].line;
								newColumn -= movementArray[i].column;

								if ((i == 0) || (i == 2))
								{
									for (int j = 1; j <= 3; j += 2)
									{
										int nextLine = newLine + movementArray[j].line;
										int nextColumn = newColumn + movementArray[j].column;

										if (quoridorMatrix[nextLine][nextColumn] == 0)
										{
											nextLine += movementArray[j].line;
											nextColumn += movementArray[j].column;

											shadows[(nextLine - 1) / 2][(nextColumn - 1) / 2].setFillColor(lightGreen);
										}
									}
								}
								else
								{
									for (int j = 0; j <= 2; j += 2)
									{
										int nextLine = newLine + movementArray[j].line;
										int nextColumn = newColumn + movementArray[j].column;

										if (quoridorMatrix[newLine][newColumn] == 0)
										{
											nextLine += movementArray[j].line;
											nextColumn += movementArray[j].column;

											shadows[(nextLine - 1) / 2][(nextColumn - 1) / 2].setFillColor(lightGreen);
										}
									}
								}
							}
						}
					}
				}
			}
			else
			{
				for (int i = 0; i <= 3; i++)
				{
					int newLine = AI.position.line + movementArray[i].line;
					int newColumn = AI.position.column + movementArray[i].column;
					if (quoridorMatrix[newLine][newColumn] == 0)
					{
						newLine += movementArray[i].line;
						newColumn += movementArray[i].column;

						if (quoridorMatrix[newLine][newColumn] == 0)
							shadows[(newLine - 1) / 2][(newColumn - 1) / 2].setFillColor(sf::Color::Magenta);
						else
						{
							newLine += movementArray[i].line;
							newColumn += movementArray[i].column;

							if (quoridorMatrix[newLine][newColumn] == 0)
							{
								newLine += movementArray[i].line;
								newColumn += movementArray[i].column;

								shadows[(newLine - 1) / 2][(newColumn - 1) / 2].setFillColor(sf::Color::Magenta);
							}
							else
							{
								newLine -= movementArray[i].line;
								newColumn -= movementArray[i].column;

								if ((i == 0) || (i == 2))
								{
									for (int j = 1; j <= 3; j += 2)
									{
										int nextLine = newLine + movementArray[j].line;
										int nextColumn = newColumn + movementArray[j].column;

										if (quoridorMatrix[nextLine][nextColumn] == 0)
										{
											nextLine += movementArray[j].line;
											nextColumn += movementArray[j].column;

											shadows[(nextLine - 1) / 2][(nextColumn - 1) / 2].setFillColor(sf::Color::Magenta);
										}
									}
								}
								else
								{
									for (int j = 0; j <= 2; j += 2)
									{
										int nextLine = newLine + movementArray[j].line;
										int nextColumn = newColumn + movementArray[j].column;

										if (quoridorMatrix[nextLine][nextColumn] == 0)
										{
											nextLine += movementArray[j].line;
											nextColumn += movementArray[j].column;

											shadows[(nextLine - 1) / 2][(nextColumn - 1) / 2].setFillColor(sf::Color::Magenta);
										}
									}
								}
							}
						}
					}
				}
			}

			window.clear();
			printQuoridorInVsAI(shadows);
			window.display();

			if (switchPlayers == true)
			{
				int lengthOfAI = 0;
				int lengthOfSecondPlayer = 0;
				int leeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];
				int nextLine = 0;
				int nextColumn = 0;

				copyTwoMatrices(quoridorMatrix, leeMatrix);
				lengthOfSecondPlayer = findLength(leeMatrix, secondPlayer, 1, nextLine, nextColumn, false );

				copyTwoMatrices(quoridorMatrix, leeMatrix);
				lengthOfAI = findLength(leeMatrix, AI, 17, nextLine, nextColumn, false );

				if ( (lengthOfAI <= lengthOfSecondPlayer) || ( AI.numberOfWallsLeft == 0) )
					movePawn(quoridorMatrix, AI, switchPlayers, nextLine, nextColumn, true);
				else 
				{
					int maximumLengthFound = 0;
					matrixPosition wallPosition;
					char wallOrientation;
					int l, c;

					for (int i = 2; i <= 16; i += 2)
						for (int j = 1; j <= 15; j += 2) {
							matrixPosition startingWall;
							startingWall.line = i;
							startingWall.column = j;
							int leeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];
							copyTwoMatrices(quoridorMatrix, leeMatrix);

							assignWall(leeMatrix, startingWall, 'h', true);
							int lengthFound = findLength(leeMatrix, secondPlayer, 1, l, c, true);

							if ( (lengthFound > maximumLengthFound) && ( quoridorMatrix[startingWall.line][startingWall.column] == 0) && (quoridorMatrix[startingWall.line][startingWall.column + 1] == 0) && (quoridorMatrix[startingWall.line][startingWall.column + 2] == 0))
							{
								maximumLengthFound = lengthFound;
								wallPosition.line = startingWall.line;
								wallPosition.column = startingWall.column;
								wallOrientation = 'h';
							}
						}

					for (int i = 1; i <= 16; i += 2)
						for (int j = 2; j <= 16; j += 2) {
							matrixPosition startingWall;
							startingWall.line = i;
							startingWall.column = j;
							int leeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];
							copyTwoMatrices(quoridorMatrix, leeMatrix);

							assignWall(leeMatrix, startingWall, 'v', true);
							int lengthFound = findLength(leeMatrix, secondPlayer, 1, l, c, true);

							if ((lengthFound > maximumLengthFound) && (quoridorMatrix[startingWall.line][startingWall.column] == 0) && (quoridorMatrix[startingWall.line + 1][startingWall.column] == 0) && (quoridorMatrix[startingWall.line + 2][startingWall.column] == 0))
							{
								maximumLengthFound = lengthFound;
								wallPosition.line = startingWall.line;
								wallPosition.column = startingWall.column;
								wallOrientation = 'v';
							}
						}

					if ( maximumLengthFound > lengthOfSecondPlayer )
					{
						AI.numberOfWallsLeft--;
						AIWalls.setString( std::to_string( AI.numberOfWallsLeft ) );
						assignWall( quoridorMatrix, wallPosition, wallOrientation, false );
					}
					else
						movePawn( quoridorMatrix, AI, switchPlayers, nextLine, nextColumn, true );
				}

				switchPlayers = false;
			}
			else
			{
				if (event.type == sf::Event::MouseButtonPressed)
				{
					sf::Vector2i mouse = sf::Mouse::getPosition(window);
					int x = mouse.x;
					int y = mouse.y;

					if (buttonForWallPressed)
					{
						if (switchPlayers == false)
						{
							// before assignWall should check if the wall position is correct ( lee )
							if ((x >= 400) && (x <= 600) && (y >= 100) && (y <= 170)) // vertical
							{
								int leeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];
								int newLeeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];
								copyTwoMatrices(quoridorMatrix, leeMatrix);
								copyTwoMatrices(quoridorMatrix, newLeeMatrix);
								assignWall(leeMatrix, verticalWallPosition, 'v', 1);
								assignWall(newLeeMatrix, verticalWallPosition, 'v', 1);

								if ((secondPlayer.numberOfWallsLeft > 0) && (leeOnLine(leeMatrix, secondPlayer, 1)) && (leeOnLine(newLeeMatrix, AI, 17)))
								{
									if ( ( quoridorMatrix[ verticalWallPosition.line ][ verticalWallPosition.column ] == 0 ) && ( quoridorMatrix[ verticalWallPosition.line + 1 ][ verticalWallPosition.column ] == 0 ) && ( quoridorMatrix[ verticalWallPosition.line + 2 ][ verticalWallPosition.column ] == 0 ) )
									{
										assignWall( quoridorMatrix, verticalWallPosition, 'v', 0 );
										secondPlayer.numberOfWallsLeft--;
										secondPlayerWalls.setString( std::to_string( secondPlayer.numberOfWallsLeft ) );
										switchPlayers = true;
									}
								}
							}
							if ((x >= 400) && (x <= 600) && (y >= 200) && (y <= 270)) // horizontal
							{
								int leeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];
								int newLeeMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];
								copyTwoMatrices(quoridorMatrix, leeMatrix);
								copyTwoMatrices(quoridorMatrix, newLeeMatrix);
								assignWall(leeMatrix, horizontalWallPosition, 'h', 1);
								assignWall(newLeeMatrix, horizontalWallPosition, 'v', 1);

								if ((secondPlayer.numberOfWallsLeft > 0) && (leeOnLine(leeMatrix, secondPlayer, 1)) && (leeOnLine(newLeeMatrix, AI, 17)))
								{
									if ( ( quoridorMatrix[ horizontalWallPosition.line ][ horizontalWallPosition.column ] == 0 ) && ( quoridorMatrix[ horizontalWallPosition.line ][ horizontalWallPosition.column + 1 ] == 0 ) && ( quoridorMatrix[ horizontalWallPosition.line ][ horizontalWallPosition.column + 2 ] == 0 ) )
									{
										assignWall( quoridorMatrix, horizontalWallPosition, 'h', 0 );
										secondPlayer.numberOfWallsLeft--;
										secondPlayerWalls.setString( std::to_string( secondPlayer.numberOfWallsLeft ) );
										switchPlayers = true;
									}
								}
							}
							buttonForWallPressed = false;
							verticalButton.setFillColor( darkBrown );
							horizontalButton.setFillColor( darkBrown );
						}
					}
					if (x >= 12 && x <= (15 + 25) * 9 + 12 && y >= 10 && y <= (15 + 25) * 9 + 10)
					{
						int j = (x - 12) / (25 + 15);
						int i = (y - 10) / (25 + 15);

						int offsetX = j * (25 + 15) + 12;
						int offsetY = i * (25 + 15) + 10;

						if (x > offsetX + 0 && x < offsetX + 25 && y > offsetY + 0 && y < offsetY + 25)
						{
							// apelez ca vrea sa mute pionul
							if (switchPlayers == false)
							{
								if ( shadows[ i ][ j ].getFillColor() == lightGreen )
								{
									movePawn( quoridorMatrix, secondPlayer, switchPlayers, 2 * i + 1, 2 * j + 1, false );
									switchPlayers = true;
								}
							}
						}
						if (x > offsetX + 25 && x < offsetX + 25 + 15 && y > offsetY + 25 && y < offsetY + 25 + 15)
						{
							verticalWallPosition.line = 2 * i + 1;
							verticalWallPosition.column = 2 * j + 2;
							horizontalWallPosition.line = 2 * i + 2;
							horizontalWallPosition.column = 2 * j + 1;
							buttonForWallPressed = true;
							verticalButton.setFillColor(brown);
							horizontalButton.setFillColor(brown);
						}


					}
					else if ((x >= 650) && (y >= 600) && (x <= 800) && (y <= 680)) // go back
						startMenu();
				}
			}

			if (AI.position.line == 17)
				AIWon.setFillColor(purple);
			if (secondPlayer.position.line == 1)
				secondPlayerWon.setFillColor(Green);
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}
