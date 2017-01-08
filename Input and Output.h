#pragma once
#include "Data Structures and Constants."h

void printQuoridor()
{
	sf::RenderWindow window( sf::VideoMode( 640, 480 ), "SFML Application" );
	sf::RectangleShape rectangles[ 10 ][ 10 ];
	int line = 10;
	int column = 12;
	int adder = 40;

	for ( int i = 0; i < 9; i++ )
	{
		rectangles[ i ][ 0 ].setPosition( column, line );
		rectangles[ i ][ 0 ].setSize( sf::Vector2f( SQUARE_SIDE, SQUARE_SIDE ) );
		for ( int j = 1; j < 9; j++ )
		{
			column += adder;
			rectangles[ i ][ j ].setSize( sf::Vector2f( SQUARE_SIDE, SQUARE_SIDE ) );
			rectangles[ i ][ j ].setPosition( column, line );
		}
		line += adder;
		column = 12;
	}

	rectangles[ 0 ][ 4 ].setFillColor( sf::Color::Red );
	rectangles[ 8 ][ 4 ].setFillColor( sf::Color::Green );

	while ( window.isOpen() )
	{
		sf::Event event;
		while ( window.pollEvent( event ) )
		{
			if ( event.type == sf::Event::MouseButtonPressed )
				std::cout << "da"; // schimba cu verificarea pozitiei de pixeli unde s-a apasat cu mouse-ul
			if ( event.type == sf::Event::Closed )
				window.close();
		}
		window.clear();

		for ( int i = 0; i < 9; i++ )
			for ( int j = 0; j < 9; j++ )
				window.draw( rectangles[ i ][ j ] );

		window.display();
	}
}
