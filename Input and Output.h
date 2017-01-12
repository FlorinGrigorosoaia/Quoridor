#pragma once
#include "Data Structures and Constants.h"
#include "Functions.h"

sf::RenderWindow window( sf::VideoMode( DIM_OF_WIN_OX, DIM_OF_WIN_OY ), "Quoridor" );

sf::RectangleShape oneVsOneButton;
sf::RectangleShape fourPlayersButton;
sf::RectangleShape vsAIButton;
sf::RectangleShape goBackToStartMenuButton;
sf::RectangleShape verticalButton;
sf::RectangleShape horizontalButton;

sf::Font font;
sf::Text oneVsOneText( "Play 1 vs 1", font );
sf::Text fourPlayersText( "Four players mode", font );
sf::Text vsAIText( "Play against AI", font );
sf::Text detailsText( "Quoridor 2017\n   created by\nFlorin Grigorosoaia\nCatalin Marculet", font );
sf::Text goBackToStartMenuText( "Back", font );
sf::Text verticalButtonText( "      Add\nvertical wall", font );
sf::Text horizontalButtonText( "        Add\nhorizontal wall", font );
sf::Text firstPlayerNumberOfWallsLeft( "Walls available for red", font );
sf::Text secondPlayerNumberOfWallsLeft( "Walls available for green", font );
sf::Text firstPlayerWalls( std::to_string( firstPlayer.numberOfWallsLeft ), font );
sf::Text secondPlayerWalls( std::to_string( secondPlayer.numberOfWallsLeft ), font );
sf::Text firstPlayerWon( "Red has won", font );
sf::Text secondPlayerWon( "Green has won", font );

void printQuoridor( sf::RectangleShape whatToPrint[ 10 ][ 10 ] );
void playOneVsOne();

void buildColors()
{
	brown.r = 112;
	brown.g = 79;
	brown.b = 21;

	lightGreen.r = 178;
	lightGreen.g = 255;
	lightGreen.b = 102;

	lightRed.r = 255;
	lightRed.g = 153;
	lightRed.b = 153;
}

void buildTexts()
{
	font.loadFromFile( "arial.ttf" );

	oneVsOneText.setCharacterSize( FONT_SIZE );
	oneVsOneText.setStyle( sf::Text::Bold );
	oneVsOneText.setPosition( 395, 100 );
	oneVsOneText.setFillColor( sf::Color::White );

	vsAIText.setCharacterSize( FONT_SIZE );
	vsAIText.setStyle( sf::Text::Bold );
	vsAIText.setPosition( 375, 270 );
	vsAIText.setFillColor( sf::Color::Cyan );

	fourPlayersText.setCharacterSize( FONT_SIZE );
	fourPlayersText.setStyle( sf::Text::Bold );
	fourPlayersText.setPosition( 358, 440 );
	fourPlayersText.setFillColor( sf::Color::Magenta );

	detailsText.setCharacterSize( 15 );
	detailsText.setStyle( sf::Text::Italic );
	detailsText.setPosition( 680, 600 );

	goBackToStartMenuText.setCharacterSize( FONT_SIZE );
	goBackToStartMenuText.setStyle( sf::Text::Bold );
	goBackToStartMenuText.setPosition( 703, 627 );

	verticalButtonText.setCharacterSize( 15 );
	verticalButtonText.setStyle( sf::Text::Bold );
	verticalButtonText.setPosition( 453, 115 );

	horizontalButtonText.setCharacterSize( 15 );
	horizontalButtonText.setStyle( sf::Text::Bold );
	horizontalButtonText.setPosition( 446, 215 );

	firstPlayerNumberOfWallsLeft.setCharacterSize( 15 );
	firstPlayerNumberOfWallsLeft.setStyle( sf::Text::Bold );
	firstPlayerNumberOfWallsLeft.setPosition( 650, 115 );

	secondPlayerNumberOfWallsLeft.setCharacterSize( 15 );
	secondPlayerNumberOfWallsLeft.setStyle( sf::Text::Bold );
	secondPlayerNumberOfWallsLeft.setPosition( 650, 215 );

	firstPlayerWalls.setCharacterSize( 15 );
	firstPlayerWalls.setStyle( sf::Text::Bold );
	firstPlayerWalls.setPosition( 725, 132 );

	secondPlayerWalls.setCharacterSize( 15 );
	secondPlayerWalls.setStyle( sf::Text::Bold );
	secondPlayerWalls.setPosition( 725, 232 );

	firstPlayerWon.setCharacterSize( 40 );
	firstPlayerWon.setStyle( sf::Text::Bold );
	firstPlayerWon.setPosition( 300, 500 );
	firstPlayerWon.setFillColor( sf::Color::Transparent );

	secondPlayerWon.setCharacterSize( 40 );
	secondPlayerWon.setStyle( sf::Text::Bold );
	secondPlayerWon.setPosition( 300, 500 );
	secondPlayerWon.setFillColor( sf::Color::Transparent );
}

void buildButtons()
{
	oneVsOneButton.setSize( sf::Vector2f( DIM_OF_BUTTON_OX, DIM_OF_BUTTON_OY ) );
	oneVsOneButton.setPosition( 335, 50 );
	oneVsOneButton.setFillColor( sf::Color::Blue );

	vsAIButton.setSize( sf::Vector2f( DIM_OF_BUTTON_OX, DIM_OF_BUTTON_OY ) );
	vsAIButton.setPosition( 335, 220 );
	vsAIButton.setFillColor( sf::Color::Blue );

	fourPlayersButton.setSize( sf::Vector2f( DIM_OF_BUTTON_OX, DIM_OF_BUTTON_OY ) );
	fourPlayersButton.setPosition( 335, 390 );
	fourPlayersButton.setFillColor( sf::Color::Blue );

	goBackToStartMenuButton.setSize( sf::Vector2f( 150, 80 ) );
	goBackToStartMenuButton.setPosition( 650, 600 );
	goBackToStartMenuButton.setFillColor( sf::Color::Green );

	verticalButton.setSize( sf::Vector2f( 200, 70 ) );
	verticalButton.setPosition( 400, 100 );
	verticalButton.setFillColor( sf::Color::Red );

	horizontalButton.setSize( sf::Vector2f( 200, 70 ) );
	horizontalButton.setPosition( 400, 200 );
	horizontalButton.setFillColor( sf::Color::Red );
}

void printStartMenu()
{
	window.draw( oneVsOneButton );
	window.draw( vsAIButton );
	window.draw( fourPlayersButton );

	window.draw( oneVsOneText );
	window.draw( vsAIText );
	window.draw( fourPlayersText );
	window.draw( detailsText );
}

void buildVerticalWalls()
{
	int axaX = 37;
	int axaY = 10;
	int adder = 40;

	for ( int i = 0; i < 8; i++ )
	{
		verticalWalls[ i ][ 0 ].setPosition( axaX, axaY );
		verticalWalls[ i ][ 0 ].setSize( sf::Vector2f( 15, 65 ) );
		verticalWalls[ i ][ 0 ].setFillColor( sf::Color::Transparent );
		for ( int j = 1; j < 8; j++ )
		{
			axaX += adder;
			verticalWalls[ i ][ j ].setSize( sf::Vector2f( 15, 65 ) );
			verticalWalls[ i ][ j ].setPosition( axaX, axaY );
			verticalWalls[ i ][ j ].setFillColor( sf::Color::Transparent );
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

	for ( int i = 0; i < 8; i++ )
	{
		horizontalWalls[ i ][ 0 ].setPosition( axaX, axaY );
		horizontalWalls[ i ][ 0 ].setSize( sf::Vector2f( 65, 15 ) );
		horizontalWalls[ i ][ 0 ].setFillColor( sf::Color::Transparent );
		for ( int j = 1; j < 8; j++ )
		{
			axaX += adder;
			horizontalWalls[ i ][ j ].setSize( sf::Vector2f( 65, 15 ) );
			horizontalWalls[ i ][ j ].setPosition( axaX, axaY );
			horizontalWalls[ i ][ j ].setFillColor( sf::Color::Transparent );
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

	for ( int i = 0; i < 9; i++ )
	{
		rectangles[ i ][ 0 ].setPosition( axaX, axaY );
		rectangles[ i ][ 0 ].setSize( sf::Vector2f( SQUARE_SIDE, SQUARE_SIDE ) );
		rectangles[ i ][ 0 ].setFillColor( sf::Color::White );
		for ( int j = 1; j < 9; j++ )
		{
			axaX += adder;
			rectangles[ i ][ j ].setSize( sf::Vector2f( SQUARE_SIDE, SQUARE_SIDE ) );
			rectangles[ i ][ j ].setPosition( axaX, axaY );
			rectangles[ i ][ j ].setFillColor( sf::Color::White );
		}
		axaY += adder;
		axaX = 12;
	}
}

void initializeRectangles()
{
	for ( int i = 0; i < 9; i++ )
		for ( int j = 0; j < 9; j++ )
			rectangles[ i ][ j ].setFillColor( sf::Color::White );
}

void initializeWonText()
{
	firstPlayerWon.setFillColor( sf::Color::Transparent );
	secondPlayerWon.setFillColor( sf::Color::Transparent );
}

void initializeWalls()
{
	for ( int i = 0; i<8; i++ )
		for ( int j = 0; j<8; j++ )
		{
			verticalWalls[ i ][ j ].setFillColor( sf::Color::Transparent );
			horizontalWalls[ i ][ j ].setFillColor( sf::Color::Transparent );
		}
}

void startMenu()
{
	while ( window.isOpen() )
	{
		sf::Event event;

		while ( window.pollEvent( event ) )
		{
			if ( event.type == sf::Event::Closed )
				window.close();
			else if ( event.type == sf::Event::MouseButtonPressed )
			{
				sf::Vector2i mouse = sf::Mouse::getPosition( window );
				if ( ( mouse.x >= 335 ) && ( mouse.x <= 335 + DIM_OF_BUTTON_OX ) && ( mouse.y >= 50 ) && ( mouse.y <= 50 + DIM_OF_BUTTON_OY ) )
					playOneVsOne();
				//else // verificare pentru butonul cu 4 players
					// call play4players()
			}
		}

		window.clear();
		printStartMenu();
		window.display();
	}
}

void printQuoridor( sf::RectangleShape whatToPrint[ 10 ][ 10 ] )
{
	for ( int i = 0; i < 9; i++ )
		for ( int j = 0; j < 9; j++ )
			window.draw( whatToPrint[ i ][ j ] );
	for ( int i = 0; i < 8; i++ )
		for ( int j = 0; j < 8; j++ )
			window.draw( verticalWalls[ i ][ j ] );
	for ( int i = 0; i < 8; i++ )
		for ( int j = 0; j < 8; j++ )
			window.draw( horizontalWalls[ i ][ j ] );
	window.draw( goBackToStartMenuButton );
	window.draw( goBackToStartMenuText );
	window.draw( verticalButton );
	window.draw( horizontalButton );
	window.draw( verticalButtonText );
	window.draw( horizontalButtonText );
	window.draw( firstPlayerNumberOfWallsLeft );
	window.draw( secondPlayerNumberOfWallsLeft );
	window.draw( firstPlayerWalls );
	window.draw( secondPlayerWalls );
	window.draw( firstPlayerWon );
	window.draw( secondPlayerWon );
}

void playOneVsOne()
{
	initializeRectangles();
	initializeWonText();
	initializeWalls();
	bool buttonForWallPressed = false;
	matrixPosition verticalWallPosition;
	matrixPosition horizontalWallPosition;
	bool switchPlayers = true; // firstPlayer moves
	setBorder( quoridorMatrix );
	setNeededData( quoridorMatrix, switchPlayers );
	firstPlayerWalls.setString( std::to_string( firstPlayer.numberOfWallsLeft ) );
	secondPlayerWalls.setString( std::to_string( secondPlayer.numberOfWallsLeft ) );

	while ( window.isOpen() )
	{
		sf::Event event;
		while ( window.pollEvent( event ) )
		{
			copyTwoRectangles( shadows, rectangles );

			if ( switchPlayers == true )
			{
				for ( int i = 0; i <= 3; i++ )
				{
					int newLine = firstPlayer.position.line + movementArray[ i ].line;
					int newColumn = firstPlayer.position.column + movementArray[ i ].column;

					if ( quoridorMatrix[ newLine ][ newColumn ] == 0 )
					{
						newLine += movementArray[ i ].line;
						newColumn += movementArray[ i ].column;

						if ( quoridorMatrix[ newLine ][ newColumn ] == 0 )
							shadows[ ( newLine - 1 ) / 2 ][ ( newColumn - 1 ) / 2 ].setFillColor( lightRed );
						else
						{
							newLine += movementArray[ i ].line;
							newColumn += movementArray[ i ].column;

							if ( quoridorMatrix[ newLine ][ newColumn ] == 0 )
							{
								newLine += movementArray[ i ].line;
								newColumn += movementArray[ i ].column;

								shadows[ ( newLine - 1 ) / 2 ][ ( newColumn - 1 ) / 2 ].setFillColor( lightRed );
							}
							else
							{
								newLine -= movementArray[ i ].line;
								newColumn -= movementArray[ i ].column;

								if ( ( i == 0 ) || ( i == 2 ) )
								{
									for ( int j = 1; j <= 3; j += 2 )
									{
										int nextLine = newLine + movementArray[ j ].line;
										int nextColumn = newColumn + movementArray[ j ].column;

										if ( quoridorMatrix[ nextLine ][ nextColumn ] == 0 )
										{
											nextLine += movementArray[ j ].line;
											nextColumn += movementArray[ j ].column;

											shadows[ ( nextLine - 1 ) / 2 ][ ( nextColumn - 1 ) / 2 ].setFillColor( lightRed );
										}
									}
								}
								else
								{
									for ( int j = 0; j <= 2; j += 2 )
									{
										int nextLine = newLine + movementArray[ j ].line;
										int nextColumn = newColumn + movementArray[ j ].column;

										if ( quoridorMatrix[ newLine ][ newColumn ] == 0 )
										{
											nextLine += movementArray[ j ].line;
											nextColumn += movementArray[ j ].column;

											shadows[ ( nextLine - 1 ) / 2 ][ ( nextLine - 1 ) / 2 ].setFillColor( lightRed );
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
				for ( int i = 0; i <= 3; i++ )
				{
					int newLine = secondPlayer.position.line + movementArray[ i ].line;
					int newColumn = secondPlayer.position.column + movementArray[ i ].column;
					if ( quoridorMatrix[ newLine ][ newColumn ] == 0 )
					{
						newLine += movementArray[ i ].line;
						newColumn += movementArray[ i ].column;

						if ( quoridorMatrix[ newLine ][ newColumn ] == 0 )
							shadows[ ( newLine - 1 ) / 2 ][ ( newColumn - 1 ) / 2 ].setFillColor( lightGreen );
						else
						{
							newLine += movementArray[ i ].line;
							newColumn += movementArray[ i ].column;

							if ( quoridorMatrix[ newLine ][ newColumn ] == 0 )
							{
								newLine += movementArray[ i ].line;
								newColumn += movementArray[ i ].column;

								shadows[ ( newLine - 1 ) / 2 ][ ( newColumn - 1 ) / 2 ].setFillColor( lightGreen );
							}
							else
							{
								newLine -= movementArray[ i ].line;
								newColumn -= movementArray[ i ].column;

								if ( ( i == 0 ) || ( i == 2 ) )
								{
									for ( int j = 1; j <= 3; j += 2 )
									{
										int nextLine = newLine + movementArray[ j ].line;
										int nextColumn = newColumn + movementArray[ j ].column;

										if ( quoridorMatrix[ nextLine ][ nextColumn ] == 0 )
										{
											nextLine += movementArray[ j ].line;
											nextColumn += movementArray[ j ].column;

											shadows[ ( nextLine - 1 ) / 2 ][ ( nextColumn - 1 ) / 2 ].setFillColor( lightGreen );
										}
									}
								}
								else
								{
									for ( int j = 0; j <= 2; j += 2 )
									{
										int nextLine = newLine + movementArray[ j ].line;
										int nextColumn = newColumn + movementArray[ j ].column;

										if ( quoridorMatrix[ nextLine ][ nextColumn ] == 0 )
										{
											nextLine += movementArray[ j ].line;
											nextColumn += movementArray[ j ].column;

											shadows[ ( nextLine - 1 ) / 2 ][ ( nextColumn - 1 ) / 2 ].setFillColor( lightGreen );
										}
									}
								}
							}
						}
					}
				}
			}

			window.clear();
			printQuoridor( shadows );
			window.display();

			if ( event.type == sf::Event::MouseButtonPressed )
			{
				sf::Vector2i mouse = sf::Mouse::getPosition( window );
				int x = mouse.x;
				int y = mouse.y;

				if ( buttonForWallPressed )
				{
					if ( switchPlayers == true )
					{
						// before assignWall should check if the wall position is correct ( lee )
						if ( ( x >= 400 ) && ( x <= 600 ) && ( y >= 100 ) && ( y <= 170 ) ) // vertical
						{
							int leeMatrix[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ];
							int newLeeMatrix[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ];
							copyTwoMatrices( quoridorMatrix, leeMatrix );
							copyTwoMatrices( quoridorMatrix, newLeeMatrix );
							assignWall( leeMatrix, verticalWallPosition, 'v', 1 );

							if ( ( firstPlayer.numberOfWallsLeft > 0 ) && ( lee( leeMatrix, secondPlayer, 1 ) ) && ( lee( newLeeMatrix, firstPlayer, 17 ) ) )
							{
								assignWall( quoridorMatrix, verticalWallPosition, 'v', 0 );
								firstPlayer.numberOfWallsLeft--;
								firstPlayerWalls.setString( std::to_string( firstPlayer.numberOfWallsLeft ) );
								switchPlayers = false;
							}
						}
						if ( ( x >= 400 ) && ( x <= 600 ) && ( y >= 200 ) && ( y <= 270 ) ) // horizontal
						{
							int leeMatrix[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ];
							int newLeeMatrix[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ];
							copyTwoMatrices( quoridorMatrix, leeMatrix );
							copyTwoMatrices( quoridorMatrix, newLeeMatrix );
							assignWall( leeMatrix, horizontalWallPosition, 'h', 1 );

							if ( ( firstPlayer.numberOfWallsLeft > 0 ) && ( lee( leeMatrix, secondPlayer, 1 ) ) && ( lee( newLeeMatrix, firstPlayer, 17 ) ) )
							{
								assignWall( quoridorMatrix, horizontalWallPosition, 'h', 0 );
								firstPlayer.numberOfWallsLeft--;
								firstPlayerWalls.setString( std::to_string( firstPlayer.numberOfWallsLeft ) );
								switchPlayers = false;
							}
						}
						buttonForWallPressed = false;
						verticalButton.setFillColor( sf::Color::Red );
						horizontalButton.setFillColor( sf::Color::Red );
					}
					else
					{
						// before assignWall should check if the wall position is correct ( lee )
						if ( ( x >= 400 ) && ( x <= 600 ) && ( y >= 100 ) && ( y <= 170 ) ) // vertical
						{
							int leeMatrix[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ];
							int newLeeMatrix[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ];
							copyTwoMatrices( quoridorMatrix, leeMatrix );
							copyTwoMatrices( quoridorMatrix, newLeeMatrix );
							assignWall( leeMatrix, verticalWallPosition, 'v', 1 );

							if ( ( secondPlayer.numberOfWallsLeft > 0 ) && ( lee( leeMatrix, firstPlayer, 17 ) ) && ( lee( newLeeMatrix, secondPlayer, 1 ) ) )
							{
								assignWall( quoridorMatrix, verticalWallPosition, 'v', 0 );
								secondPlayer.numberOfWallsLeft--;
								secondPlayerWalls.setString( std::to_string( secondPlayer.numberOfWallsLeft ) );
								switchPlayers = true;
							}
						}
						if ( ( x >= 400 ) && ( x <= 600 ) && ( y >= 200 ) && ( y <= 270 ) ) // horizontal
						{
							int leeMatrix[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ];
							int newLeeMatrix[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ];
							copyTwoMatrices( quoridorMatrix, leeMatrix );
							copyTwoMatrices( quoridorMatrix, newLeeMatrix );
							assignWall( leeMatrix, horizontalWallPosition, 'h', 1 );

							if ( ( secondPlayer.numberOfWallsLeft > 0 ) && ( lee( leeMatrix, firstPlayer, 17 ) ) && ( lee( newLeeMatrix, secondPlayer, 1 ) ) )
							{
								assignWall( quoridorMatrix, horizontalWallPosition, 'h', 0 );
								secondPlayer.numberOfWallsLeft--;
								secondPlayerWalls.setString( std::to_string( secondPlayer.numberOfWallsLeft ) );
								switchPlayers = true;
							}
						}
						buttonForWallPressed = false;
						verticalButton.setFillColor( sf::Color::Red );
						horizontalButton.setFillColor( sf::Color::Red );
					}
				}

				if ( x >= 12 && x <= ( 15 + 25 ) * 9 + 12 && y >= 10 && y <= ( 15 + 25 ) * 9 + 10 )
				{
					int j = ( x - 12 ) / ( 25 + 15 );
					int i = ( y - 10 ) / ( 25 + 15 );

					int offsetX = j * ( 25 + 15 ) + 12;
					int offsetY = i * ( 25 + 15 ) + 10;

					if ( x > offsetX + 0 && x < offsetX + 25 && y > offsetY + 0 && y < offsetY + 25 )
					{
						// apelez ca vrea sa mute pionul
						if ( switchPlayers == true )
						{
							movePawn( quoridorMatrix, firstPlayer, switchPlayers, 2 * i + 1, 2 * j + 1 );
							switchPlayers = false;
						}
						else
						{
							movePawn( quoridorMatrix, secondPlayer, switchPlayers, 2 * i + 1, 2 * j + 1 );
							switchPlayers = true;
						}
					}
					if ( x > offsetX + 25 && x < offsetX + 25 + 15 && y > offsetY + 25 && y < offsetY + 25 + 15 )
					{
						//std::cout << "WALL" << '\n'; // retin ca vrea sa puna zid
						//std::cout << " VERTICAL: " << '\n' << "liniile:" << 2 * i + 1 << ' ' << 2 * i + 2 << ' ' << 2 * i + 3 << '\n' << " coloana: " << 2 * j + 2 << '\n';
						//std::cout << " HORIZONTAL: " << '\n' << "linia:" << 2 * i + 2 << '\n' << "coloanele:" << 2 * j + 1 << ' ' << 2 * j + 2 << ' ' << 2 * j + 3 << '\n';
						verticalWallPosition.line = 2 * i + 1;
						verticalWallPosition.column = 2 * j + 2;
						horizontalWallPosition.line = 2 * i + 2;
						horizontalWallPosition.column = 2 * j + 1;
						buttonForWallPressed = true;
						verticalButton.setFillColor( brown );
						horizontalButton.setFillColor( brown );
					}
				}
				else if ( ( x >= 650 ) && ( y >= 600 ) && ( x <= 800 ) && ( y <= 680 ) ) // go back
					startMenu();
			}
			if ( firstPlayer.position.line == 17 )
				firstPlayerWon.setFillColor( sf::Color::Red );
			if ( secondPlayer.position.line == 1 )
				secondPlayerWon.setFillColor( sf::Color::Green );
			if ( event.type == sf::Event::Closed )
				window.close();
		}
	}
}
