#include "Data Structures and Constants.h"


void setBorder( int matrixWhereToSetBorder[][] )
{
	for ( int i = 0; i < NO_LIN_COL; i++ )
	{
		matrixWhereToSetBorder[ i ][ 0 ] = matrixWhereToSetBorder[ i ][ NO_LIN_COL - 1 ] = BORDER;
		matrixWhereToSetBorder[ 0 ][ i ] = matrixWhereToSetBorder[ NO_LIN_COL - 1 ][ i ] = BORDER;
	}
}

void assignUsedCell( int matrixWhereToAssign[][], player currentPlayer )
{
	matrixWhereToAssign[ currentPlayer.position.line ][ currentPlayer.position.column ] = currentPlayer.pawn;
}

void assignFreeCell( int matrixWhereToAssign[][], player currentPlayer )
{
	matrixWhereToAssign[ currentPlayer.position.line ][ currentPlayer.position.column ] = FREE;
}

void initializeMovementArray( matrixPosition movementArrayToInitialize[] )
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

void assignWall( int matrixWhereToAssign, matrixPosition startingWallPosition, char direction )
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


