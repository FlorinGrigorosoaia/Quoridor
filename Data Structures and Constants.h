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

#define SQUARE_SIDE 25
#define DIM_OF_WIN_OX 900
#define DIM_OF_WIN_OY 700
#define DIM_OF_BUTTON_OX 230
#define DIM_OF_BUTTON_OY 120

struct matrixPosition
{
	int line;
	int column;
};

struct player
{
	matrixPosition position;
	char nameOfPlayer[MAX_LENGTH_NAME];
	int pawn;
};

char possibleMoves[] = { 'u', 'r', 'd', 'l' };

int quoridorMatrix[NO_LIN_COL + 1][NO_LIN_COL + 1];

matrixPosition movementArray[NO_DIRECTIONS];

player firstPlayer;
player secondPlayer;
