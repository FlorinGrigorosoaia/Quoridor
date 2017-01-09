#pragma once
#include "Data Structures and Constants.h"

sf::RenderWindow window(sf::VideoMode(DIM_OF_WIN_OX, DIM_OF_WIN_OY), "Quoridor");
sf::RectangleShape oneVsOneButton;
sf::RectangleShape fourPlayersButton;
sf::RectangleShape vsAIButton;

void buildStartMenuButtons()
{
	oneVsOneButton.setSize(sf::Vector2f(DIM_OF_BUTTON_OX, DIM_OF_BUTTON_OY));
	oneVsOneButton.setPosition(335, 50);
	oneVsOneButton.setFillColor(sf::Color::Red);

	vsAIButton.setSize(sf::Vector2f(DIM_OF_BUTTON_OX, DIM_OF_BUTTON_OY));
	vsAIButton.setPosition(335, 220);
	vsAIButton.setFillColor(sf::Color::Yellow);

	fourPlayersButton.setSize(sf::Vector2f(DIM_OF_BUTTON_OX, DIM_OF_BUTTON_OY));
	fourPlayersButton.setPosition(335, 390);
	fourPlayersButton.setFillColor(sf::Color::Blue);
}

void printStartMenu()
{
	window.draw(oneVsOneButton);
	window.draw(vsAIButton);
	window.draw(fourPlayersButton);
	/*sf::Text text;
	text.setString( "dada" );
	text.setFillColor( sf::Color::Cyan );
	window.draw( text );*/
}

void startMenu()
{
	buildStartMenuButtons();

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

			}
		}

		window.clear();
		printStartMenu();
		window.display();
	}
}


void printQuoridor()
{
	sf::RectangleShape rectangles[10][10];
	int line = 10;
	int column = 12;
	int adder = 40;

	for (int i = 0; i < 9; i++)
	{
		rectangles[i][0].setPosition(column, line);
		rectangles[i][0].setSize(sf::Vector2f(SQUARE_SIDE, SQUARE_SIDE));
		for (int j = 1; j < 9; j++)
		{
			column += adder;
			rectangles[i][j].setSize(sf::Vector2f(SQUARE_SIDE, SQUARE_SIDE));
			rectangles[i][j].setPosition(column, line);
		}
		line += adder;
		column = 12;
	}

	rectangles[0][4].setFillColor(sf::Color::Red);
	rectangles[8][4].setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2i mouse = sf::Mouse::getPosition(window);
				int x = mouse.x;
				int y = mouse.y;

				if(x >= 12 && x <= (15 + 25) * 9 + 12 && y >= 10 && y <= (15 + 25) * 9 + 10)
				{
					int j = (x - 12) / (25 + 15);
					int i = (y - 10) / (25 + 15);

					int offsetX = j * (25 + 15) + 12;
					int offsetY = i * (25 + 15) + 10;

					if (x > offsetX + 0 && x < offsetX + 25 && y > offsetY + 0 && y < offsetY + 25)
						std::cout << "PAWN" << '\n'; // apelez ca vrea sa mute pionul
					if (x > offsetX + 25 && x < offsetX + 25 + 15 && y > offsetY + 25 && y < offsetY + 25 + 15)
						std::cout << "WALL" << '\n'; // retin ca vrea sa puna zid

				}

				//daca vrea sa puna zid si click-ul pe dreptunghiul de orizontala/verticala ; apelez functia pentru orizontala/vertcicala respectiva
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		//desenare
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				window.draw(rectangles[i][j]);

		window.display();
	}
}
