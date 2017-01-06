#pragma once
#include "Data Structures and Constants.h"
#include <iostream>

using namespace std;

void getInput( int matrixWhereToAssign[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ], player &currentPlayer, bool whichPlayer );


void printMatrix( int matrixToPrint[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ] )
{
	for ( int i = 1; i < NO_LIN_COL - 1; i++ )
	{
		for ( int j = 1; j < NO_LIN_COL - 1; j++ )
			cout << matrixToPrint[ i ][ j ] << ' ';
		cout << '\n';
	}
}

void setBorder( int matrixWhereToSetBorder[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ] )
{
	for ( int i = 0; i < NO_LIN_COL; i++ )
	{
		matrixWhereToSetBorder[ i ][ 0 ] = matrixWhereToSetBorder[ i ][ NO_LIN_COL - 1 ] = BORDER;
		matrixWhereToSetBorder[ 0 ][ i ] = matrixWhereToSetBorder[ NO_LIN_COL - 1 ][ i ] = BORDER;
	}
}

void assignUsedCell( int matrixWhereToAssign[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ], player currentPlayer )
{
	matrixWhereToAssign[ currentPlayer.position.line ][ currentPlayer.position.column ] = currentPlayer.pawn;
}

void assignFreeCell( int matrixWhereToAssign[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ], player currentPlayer )
{
	matrixWhereToAssign[ currentPlayer.position.line ][ currentPlayer.position.column ] = FREE;
}

void initializeMovementArray( matrixPosition movementArrayToInitialize[ NO_DIRECTIONS ] )
{
	movementArrayToInitialize[ 0 ].line = DECREASE;
	movementArrayToInitialize[ 0 ].column = STAND;

	movementArrayToInitialize[ 1 ].line = STAND;
	movementArrayToInitialize[ 1 ].column = INCREASE;

	movementArrayToInitialize[ 2 ].line = INCREASE;
	movementArrayToInitialize[ 2 ].column = STAND;

	movementArrayToInitialize[ 3 ].line = STAND;
	movementArrayToInitialize[ 3 ].column = DECREASE;
}

bool directionIsVertical( char directionToCheck )
{
	if ( directionToCheck == 'v' )
		return true;
	return false;
}

bool directionIsHorizontal( char directionToCheck )
{
	if ( directionToCheck == 'h' )
		return true;
	return false;
}

void assignWall( int matrixWhereToAssign[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ], matrixPosition startingWallPosition, char direction )
{
	if ( directionIsVertical( direction ) )
	{
		matrixWhereToAssign[ startingWallPosition.line ][ startingWallPosition.column ] = WALL;
		matrixWhereToAssign[ startingWallPosition.line + 1 ][ startingWallPosition.column ] = WALL;
		matrixWhereToAssign[ startingWallPosition.line + 2 ][ startingWallPosition.column ] = WALL;
	}
	if ( directionIsHorizontal( direction ) )
	{
		matrixWhereToAssign[ startingWallPosition.line ][ startingWallPosition.column ] = WALL;
		matrixWhereToAssign[ startingWallPosition.line ][ startingWallPosition.column + 1 ] = WALL;
		matrixWhereToAssign[ startingWallPosition.line ][ startingWallPosition.column + 2 ] = WALL;
	}
}

void setInitialData( player &currentPlayer )
{
	cout << " Introduceti-va numele : " << '\n';
	cin >> currentPlayer.nameOfPlayer;
	cout << currentPlayer.nameOfPlayer << ", introduceti simbolul pionului (numar intre 5 si 9) : " << '\n';
	cin >> currentPlayer.pawn;
}

void moveOnCertainDirection( int matrixWhereToAssign[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ], player &currentPlayer, int indexInMovementArray, bool whichPlayer )
{
	int newLine = currentPlayer.position.line + movementArray[ indexInMovementArray ].line;
	int newColumn = currentPlayer.position.column + movementArray[ indexInMovementArray ].column;

	if ( matrixWhereToAssign[ newLine ][ newColumn ] == 0 )
	{
		newLine += movementArray[ indexInMovementArray ].line;
		newColumn += movementArray[ indexInMovementArray ].column;

		if ( matrixWhereToAssign[ newLine ][ newColumn ] == 0 )
		{
			currentPlayer.position.line = newLine;
			currentPlayer.position.column = newColumn;
		}
		else
		{
			newLine += movementArray[ indexInMovementArray ].line;
			newColumn += movementArray[ indexInMovementArray ].column;
			if ( matrixWhereToAssign[ newLine ][ newColumn ] == 0 )
			{
				newLine += movementArray[ indexInMovementArray ].line;
				newColumn += movementArray[ indexInMovementArray ].column;
				currentPlayer.position.line = newLine;
				currentPlayer.position.column = newColumn;
			}
			else
			{
				cout << "Ati introdus o mutare gresita. " << '\n';
				getInput( matrixWhereToAssign, currentPlayer, whichPlayer );
			}
		}
	}
}

void movePawn( int matrixWhereToAssign[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ], player &currentPlayer, bool whichPlayer )
{
	cout << "Mutari posibile : ";
	for ( int i = 0; i <= 3; i++ )
	{
		int neighbourLine = currentPlayer.position.line + movementArray[ i ].line;
		int neighbourColumn = currentPlayer.position.column + movementArray[ i ].column;

		if ( matrixWhereToAssign[ neighbourLine ][ neighbourColumn ] == 0 ) // there is no wall
			cout << possibleMoves[ i ] << ' ';
	}
	cout << '\n';

	char direction;
	cout << " Pentru a muta in sus apasati 'u' + ENTER : " << '\n';
	cout << " Pentru a muta in dreapta apasati 'r' + ENTER : " << '\n';
	cout << " Pentru a muta in jos apasati 'd' + ENTER : " << '\n';
	cout << " Pentru a muta in stanga apasati 'l' + ENTER : " << '\n';
	cin >> direction;

	assignFreeCell( matrixWhereToAssign, currentPlayer );

	if ( direction == 'u' )
		moveOnCertainDirection( matrixWhereToAssign, currentPlayer, 0, whichPlayer );
	else if ( direction == 'r' )
		moveOnCertainDirection( matrixWhereToAssign, currentPlayer, 1, whichPlayer );
	else if ( direction == 'd' )
		moveOnCertainDirection( matrixWhereToAssign, currentPlayer, 2, whichPlayer );
	else
		moveOnCertainDirection( matrixWhereToAssign, currentPlayer, 3, whichPlayer );

	assignUsedCell( matrixWhereToAssign, currentPlayer );
}

void copyTwoMatrices( int matrixToBeCopied[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ], int matrixWhereToCopy[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ] )
{
	for ( int i = 0; i < NO_LIN_COL - 1; i++ )
		for ( int j = 0; j < NO_LIN_COL - 1; j++ )
			matrixWhereToCopy[ i ][ j ] = matrixToBeCopied[ i ][ j ];
}

bool lee( int matrixToCheck[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ], player &currentPlayer, int finishLine )
{
	matrixPosition leeQueue[ NO_LIN_COL * NO_LIN_COL + 5 ];
	matrixPosition currentPosition;
	leeQueue[ 0 ].line = currentPosition.line = currentPlayer.position.line;
	leeQueue[ 0 ].column = currentPosition.column = currentPlayer.position.column;
	int first = 0, last = 0;
	matrixToCheck[ currentPlayer.position.line ][ currentPlayer.position.column ] = 1;

	while ( currentPosition.line != finishLine && first <= last) {
		currentPosition.line = leeQueue[ first ].line;
		currentPosition.column = leeQueue[ first ].column;
		first++;

		for ( int i = 0; i < NO_DIRECTIONS; ++i ) {
			matrixPosition nextPosition;
			nextPosition.line = currentPosition.line + movementArray[ i ].line;
			nextPosition.column = currentPosition.column + movementArray[ i ].column;

			if ( matrixToCheck[ nextPosition.line ][ nextPosition.column ] != WALL ) {
				nextPosition.line += movementArray[ i ].line;
				nextPosition.column += movementArray[ i ].column;

				if ( matrixToCheck[ nextPosition.line ][ nextPosition.column ] == 0 ) {
					++last;
					leeQueue[ last ].line = nextPosition.line;
					leeQueue[ last ].column = nextPosition.column;
					matrixToCheck[ nextPosition.line ][ nextPosition.column ] = 1;
				}
				else if ( matrixToCheck[ nextPosition.line ][ nextPosition.column ] > 1 ) {
					nextPosition.line += 2 * movementArray[ i ].line;
					nextPosition.column += 2 * movementArray[ i ].column;

					if ( matrixToCheck[ nextPosition.line ][ nextPosition.column ] == 0 ) {
						++last;
						leeQueue[ last ].line = nextPosition.line;
						leeQueue[ last ].column = nextPosition.column;
						matrixToCheck[ nextPosition.line ][ nextPosition.column ] = 1;
					}
				}
			}
		}
	}

	if ( first > last )
		return false;
	return true;
}

void getWallInput( int matrixWhereToAssign[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ], bool whichPlayer )
{
	matrixPosition wall;
	char wallOrientation;
	int leeMatrix[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ];
	copyTwoMatrices( matrixWhereToAssign, leeMatrix );

	cout << "Introduceti linia de start a zidului : " << '\n';
	cin >> wall.line;
	cout << "Introduceti coloana de start a zidului : " << '\n';
	cin >> wall.column;
	cout << "Introduceti orientarea zidului('h'-orizontala, 'v'-verticala) : " << '\n';
	cin >> wallOrientation;

	if ( directionIsHorizontal( wallOrientation ) )
	{
		if ( wall.line % 2 == 0 )
		{
			assignWall( leeMatrix, wall, wallOrientation );
			if ( whichPlayer == true )
			{
				if ( lee( leeMatrix, secondPlayer, 1 ) )
					assignWall( matrixWhereToAssign, wall, wallOrientation );
				else
				{
					cout << " Ati introdus o pozitie gresita pentru zid. " << '\n';
					getWallInput( matrixWhereToAssign, whichPlayer );
				}
			}
			else
			{
				if ( lee( leeMatrix, firstPlayer, 17 ) )
					assignWall( matrixWhereToAssign, wall, wallOrientation );
				else
				{
					cout << " Ati introdus o pozitie gresita pentru zid. " << '\n';
					getWallInput( matrixWhereToAssign, whichPlayer );
				}
			}
		}
		else
		{
			cout << " Ati introdus o pozitie gresita pentru zid. " << '\n';
			getWallInput( matrixWhereToAssign, whichPlayer );
		}
	}
	else
	{
		if ( wall.column % 2 == 0 )
		{
			assignWall( leeMatrix, wall, wallOrientation );
			if ( whichPlayer == true )
			{
				if ( lee( leeMatrix, secondPlayer, 1 ) )
					assignWall( matrixWhereToAssign, wall, wallOrientation );
				else
				{
					cout << " Ati introdus o pozitie gresita pentru zid. " << '\n';
					getWallInput( matrixWhereToAssign, whichPlayer );
				}
			}
			else
			{
				if ( lee( leeMatrix, firstPlayer, 17 ) )
					assignWall( matrixWhereToAssign, wall, wallOrientation );
				else
				{
					cout << " Ati introdus o pozitie gresita pentru zid. " << '\n';
					getWallInput( matrixWhereToAssign, whichPlayer );
				}
			}
		}
		else
		{
			cout << " Ati introdus o pozitie gresita pentru zid. " << '\n';
			getWallInput( matrixWhereToAssign, whichPlayer );
		}
	}
}

void getInput( int matrixWhereToAssign[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ], player &currentPlayer, bool whichPlayer )
{
	char move;
	cout << " Pentru a muta pionul apasati 'p' + ENTER : " << '\n';
	cout << " Pentru a aseza un zid apasati 'w' + ENTER : " << '\n';
	cin >> move;

	if ( move == 'p' )
	{
		system( "CLS" );
		printMatrix( matrixWhereToAssign );
		movePawn( matrixWhereToAssign, currentPlayer, whichPlayer );
	}
	else
		getWallInput( matrixWhereToAssign, whichPlayer );
}

void setNeededData( int matrixWhereToAssign[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ] )
{
	firstPlayer.position.line = 1;
	firstPlayer.position.column = 9;
	secondPlayer.position.line = 17;
	secondPlayer.position.column = 9;

	assignUsedCell( matrixWhereToAssign, firstPlayer );
	assignUsedCell( matrixWhereToAssign, secondPlayer );
}

void play1vs1()
{
	bool switchPlayers = true; // firstPlayer moves
	setBorder( quoridorMatrix );
	setInitialData( firstPlayer );
	setInitialData( secondPlayer );
	setNeededData( quoridorMatrix );

	while ( ( firstPlayer.position.line != 17 ) && ( secondPlayer.position.line != 1 ) )
	{
		if ( switchPlayers == true )
		{
			system( "color B" );
			getInput( quoridorMatrix, firstPlayer, switchPlayers);
			system( "CLS" );
			printMatrix( quoridorMatrix );
			switchPlayers = false;
		}
		else
		{
			system( "color E" );
			getInput( quoridorMatrix, secondPlayer, switchPlayers );
			system( "CLS" );
			printMatrix( quoridorMatrix );
			switchPlayers = true;
		}
	}
}
