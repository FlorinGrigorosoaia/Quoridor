#pragma once

#define MAX_LENGTH_NAME 30
#define NO_LIN_COL 19
#define BORDER -1
#define WALL 2
#define FREE 0
#define DECREASE -1
#define INCREASE 1
#define STAND 0
#define NO_DIRECTIONS 4
#define PAWN 5

#define SQUARE_SIDE 25
#define DIM_OF_WIN_OX 900
#define DIM_OF_WIN_OY 700
#define DIM_OF_BUTTON_OX 230
#define DIM_OF_BUTTON_OY 120
#define FONT_SIZE 20

sf::RectangleShape rectangles[ 10 ][ 10 ];
sf::RectangleShape shadows[ 10 ][ 10 ];
sf::RectangleShape horizontalWalls[ 9 ][ 9 ];
sf::RectangleShape verticalWalls[ 9 ][ 9 ];

sf::Color brown;
sf::Color lightGreen;
sf::Color lightRed;
sf::Color lightYellow;
sf::Color Green;

struct matrixPosition
{
	int line;
	int column;
};

struct player
{
	matrixPosition position;
	char nameOfPlayer[ MAX_LENGTH_NAME ];
	int numberOfWallsLeft;
};

char possibleMoves[] = { 'u', 'r', 'd', 'l' };

int quoridorMatrix[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ];

matrixPosition movementArray[ NO_DIRECTIONS ];

player firstPlayer;
player secondPlayer;
player thirdPlayer;
player fourthPlayer;

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
sf::Text thirdPlayerNumberOfWallsLeft( "Walls available for yellow", font );
sf::Text fourthPlayerNumberOfWallsLeft( "Walls available for blue", font );

sf::Text firstPlayerWalls( std::to_string( firstPlayer.numberOfWallsLeft ), font );
sf::Text secondPlayerWalls( std::to_string( secondPlayer.numberOfWallsLeft ), font );
sf::Text thirdPlayerWalls( std::to_string( firstPlayer.numberOfWallsLeft ), font );
sf::Text fourthPlayerWalls( std::to_string( secondPlayer.numberOfWallsLeft ), font );

sf::Text firstPlayerWon( "Red has won", font );
sf::Text secondPlayerWon( "Green has won", font );
sf::Text thirdPlayerWon( "Yellow has won", font );
sf::Text fourthPlayerWon( "Blue has won", font );
