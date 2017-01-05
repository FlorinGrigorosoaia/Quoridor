#pragma once
#include "Data Structures and Constants.h"
#include <iostream>

using namespace std;

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
		matrixWhereToAssign[ startingWallPosition.line ][ startingWallPosition.column + 1 ] = WALL;
	}
	if ( directionIsHorizontal( direction ) )
	{
		matrixWhereToAssign[ startingWallPosition.line ][ startingWallPosition.column ] = WALL;
		matrixWhereToAssign[ startingWallPosition.line + 1 ][ startingWallPosition.column ] = WALL;
	}
}

void setInitialData( player &currentPlayer )
{
	cout << " Introduceti-va numele : " << '\n';
	cin >> currentPlayer.nameOfPlayer;
	cout << currentPlayer.nameOfPlayer << ", introduceti simbolul pionului (numar intre 5 si 9) : " << '\n';
	cin >> currentPlayer.pawn;
}

void move( int matrixWhereToAssign[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ], player &currentPlayer, int indexInMovementArray )
{
	int newLine = currentPlayer.position.line + 2 * movementArray[ indexInMovementArray ].line;
	int newColumn = currentPlayer.position.column + 2 * movementArray[ indexInMovementArray ].column;

	if ( matrixWhereToAssign[ newLine ][ newColumn ] == 0 )
	{
		currentPlayer.position.line = newLine;
		currentPlayer.position.column = newColumn;
	}
	else
	{
		currentPlayer.position.line = newLine + 2 * movementArray[ indexInMovementArray ].line;
		currentPlayer.position.column = newColumn + 2 * movementArray[ indexInMovementArray ].column;
	}
}

void movePawn( int matrixWhereToAssign[ NO_LIN_COL + 1 ][ NO_LIN_COL + 1 ], player &currentPlayer )
{
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
		move( matrixWhereToAssign, currentPlayer, 0 );
	else if ( direction == 'r' )
		move( matrixWhereToAssign, currentPlayer, 1 );
	else if ( direction == 'd' )
		move( matrixWhereToAssign, currentPlayer, 2 );
	else
		move( matrixWhereToAssign, currentPlayer, 3 );

	assignUsedCell( matrixWhereToAssign, currentPlayer );
}


