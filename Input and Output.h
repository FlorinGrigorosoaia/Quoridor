#pragma once
#include "Data Structures and Constants.h"

sf::RenderWindow window( sf::VideoMode( DIM_OF_WIN_OX, DIM_OF_WIN_OY ), "Quoridor" );
sf::RectangleShape rectangles[ 10 ][ 10 ];

sf::RectangleShape oneVsOneButton;
sf::RectangleShape fourPlayersButton;
sf::RectangleShape vsAIButton;
sf::RectangleShape goBackToStartMenuButton;

sf::Font font;
sf::Text oneVsOneText( "Play 1 vs 1", font );
sf::Text fourPlayersText( "Four players mode", font );
sf::Text vsAIText( "Play against AI", font );
sf::Text detailsText( "Quoridor 2017\n   created by\nFlorin Grigorosoaia\nCatalin Marculet", font );
sf::Text goBackToStartMenuText( "Back", font );

void printQuoridor();

void buildStartMenuTexts()
{
	font.loadFromFile( "arial.ttf" );

	oneVsOneText.setCharacterSize( FONT_SIZE );
	oneVsOneText.setStyle( sf::Text::Bold );
	oneVsOneText.setPosition( 395, 100 );
	oneVsOneText.setFillColor( sf::Color::Green );

	vsAIText.setCharacterSize( FONT_SIZE );
	vsAIText.setStyle( sf::Text::Bold );
	vsAIText.setPosition( 375, 270 );
	vsAIText.setFillColor( sf::Color::Magenta );

	fourPlayersText.setCharacterSize( FONT_SIZE );
	fourPlayersText.setStyle( sf::Text::Bold );
	fourPlayersText.setPosition( 358, 440 );
	fourPlayersText.setFillColor( sf::Color::Cyan );

	detailsText.setCharacterSize( 15 );
	detailsText.setStyle( sf::Text::Italic );
	detailsText.setPosition( 680, 600 );
	// additional text
	goBackToStartMenuText.setCharacterSize( FONT_SIZE );
	goBackToStartMenuText.setStyle( sf::Text::Bold );
	goBackToStartMenuText.setPosition( 703, 627 );
}

void buildStartMenuButtons()
{
	oneVsOneButton.setSize( sf::Vector2f( DIM_OF_BUTTON_OX, DIM_OF_BUTTON_OY ) );
	oneVsOneButton.setPosition( 335, 50 );
	oneVsOneButton.setFillColor( sf::Color::Red );

	vsAIButton.setSize( sf::Vector2f( DIM_OF_BUTTON_OX, DIM_OF_BUTTON_OY ) );
	vsAIButton.setPosition( 335, 220 );
	vsAIButton.setFillColor( sf::Color::Yellow );

	fourPlayersButton.setSize( sf::Vector2f( DIM_OF_BUTTON_OX, DIM_OF_BUTTON_OY ) );
	fourPlayersButton.setPosition( 335, 390 );
	fourPlayersButton.setFillColor( sf::Color::Blue );
	// additional button
	goBackToStartMenuButton.setSize( sf::Vector2f( 150, 80 ) );
	goBackToStartMenuButton.setPosition( 650, 600 );
	goBackToStartMenuButton.setFillColor( sf::Color::Green );
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

void buildRectangles()
{
	int axaY = 10;
	int axaX = 12;
	int adder = 40;

	for ( int i = 0; i < 9; i++ )
	{
		rectangles[ i ][ 0 ].setPosition( axaX, axaY );
		rectangles[ i ][ 0 ].setSize( sf::Vector2f( SQUARE_SIDE, SQUARE_SIDE ) );
		for ( int j = 1; j < 9; j++ )
		{
			axaX += adder;
			rectangles[ i ][ j ].setSize( sf::Vector2f( SQUARE_SIDE, SQUARE_SIDE ) );
			rectangles[ i ][ j ].setPosition( axaX, axaY );
		}
		axaY += adder;
		axaX = 12;
	}

	rectangles[ 0 ][ 4 ].setFillColor( sf::Color::Red );
	rectangles[ 8 ][ 4 ].setFillColor( sf::Color::Green );
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
					printQuoridor();
			}
		}

		window.clear();
		printStartMenu();
		window.display();
	}
}

void printQuoridor()
{
	while ( window.isOpen() )
	{
		sf::Event event;
		while ( window.pollEvent( event ) )
		{
			if ( event.type == sf::Event::MouseButtonPressed )
			{
				sf::Vector2i mouse = sf::Mouse::getPosition( window );
				int x = mouse.x;
				int y = mouse.y;
				if ( x >= 12 && x <= ( 15 + 25 ) * 9 + 12 && y >= 10 && y <= ( 15 + 25 ) * 9 + 10 )
				{
					int j = ( x - 12 ) / ( 25 + 15 );
					int i = ( y - 10 ) / ( 25 + 15 );

					int offsetX = j * ( 25 + 15 ) + 12;
					int offsetY = i * ( 25 + 15 ) + 10;

					if ( x > offsetX + 0 && x < offsetX + 25 && y > offsetY + 0 && y < offsetY + 25 )
						std::cout << "PAWN" << '\n'; // apelez ca vrea sa mute pionul
					if ( x > offsetX + 25 && x < offsetX + 25 + 15 && y > offsetY + 25 && y < offsetY + 25 + 15 )
						std::cout << "WALL" << '\n'; // retin ca vrea sa puna zid

				}

				//daca vrea sa puna zid si click-ul pe dreptunghiul de orizontala/verticala ; apelez functia pentru orizontala/vertcicala respectiva
				else if ( ( x >= 650 ) && ( y >= 600 ) && ( x <= 800 ) && ( y <= 680 ) ) // go back
					startMenu();
			}
			if ( event.type == sf::Event::Closed )
				window.close();
		}
		window.clear();
		for ( int i = 0; i < 9; i++ )
			for ( int j = 0; j < 9; j++ )
				window.draw( rectangles[ i ][ j ] );
		window.draw( goBackToStartMenuButton );
		window.draw( goBackToStartMenuText );

		window.display();
	}
}
