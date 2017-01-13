#pragma once
#include "Data Structures and Constants.h"
#include <iostream>

using namespace std;

void setBorder(int matrixWhereToSetBorder[NO_LIN_COL + 1][NO_LIN_COL + 1])
{
	for (int i = 0; i < NO_LIN_COL; i++)
	{
		matrixWhereToSetBorder[i][0] = matrixWhereToSetBorder[i][NO_LIN_COL - 1] = BORDER;
		matrixWhereToSetBorder[0][i] = matrixWhereToSetBorder[NO_LIN_COL - 1][i] = BORDER;
	}
}

void assignUsedCell(int matrixWhereToAssign[NO_LIN_COL + 1][NO_LIN_COL + 1], player currentPlayer, int whichPlayer, bool isAI)
{
	matrixWhereToAssign[currentPlayer.position.line][currentPlayer.position.column] = PAWN;
	if (whichPlayer == 1)
	{
		if( isAI == true) 
			rectangles[(currentPlayer.position.line - 1) / 2][(currentPlayer.position.column - 1) / 2].setFillColor(purple);
		else
			rectangles[(currentPlayer.position.line - 1) / 2][(currentPlayer.position.column - 1) / 2].setFillColor(sf::Color::Red);
	}
	else if (whichPlayer == 0)
		rectangles[(currentPlayer.position.line - 1) / 2][(currentPlayer.position.column - 1) / 2].setFillColor(Green);
	else if (whichPlayer == 2)
		rectangles[(currentPlayer.position.line - 1) / 2][(currentPlayer.position.column - 1) / 2].setFillColor(sf::Color::Yellow);
	else
		rectangles[(currentPlayer.position.line - 1) / 2][(currentPlayer.position.column - 1) / 2].setFillColor(sf::Color::Blue);
}

void assignFreeCell(int matrixWhereToAssign[NO_LIN_COL + 1][NO_LIN_COL + 1], player currentPlayer)
{
	matrixWhereToAssign[currentPlayer.position.line][currentPlayer.position.column] = FREE;
	rectangles[(currentPlayer.position.line - 1) / 2][(currentPlayer.position.column - 1) / 2].setFillColor(sf::Color::White);
}

void initializeMovementArray(matrixPosition movementArrayToInitialize[NO_DIRECTIONS])
{
	movementArrayToInitialize[0].line = DECREASE;
	movementArrayToInitialize[0].column = STAND;

	movementArrayToInitialize[1].line = STAND;
	movementArrayToInitialize[1].column = INCREASE;

	movementArrayToInitialize[2].line = INCREASE;
	movementArrayToInitialize[2].column = STAND;

	movementArrayToInitialize[3].line = STAND;
	movementArrayToInitialize[3].column = DECREASE;
}

bool directionIsVertical(char directionToCheck)
{
	if (directionToCheck == 'v')
		return true;
	return false;
}

bool directionIsHorizontal(char directionToCheck)
{
	if (directionToCheck == 'h')
		return true;
	return false;
}

void assignWall(int matrixWhereToAssign[NO_LIN_COL + 1][NO_LIN_COL + 1], matrixPosition startingWallPosition, char direction, bool leeCall)
{
	if (directionIsVertical(direction))
	{
		matrixWhereToAssign[startingWallPosition.line][startingWallPosition.column] = WALL;
		matrixWhereToAssign[startingWallPosition.line + 1][startingWallPosition.column] = WALL;
		matrixWhereToAssign[startingWallPosition.line + 2][startingWallPosition.column] = WALL;
		if (leeCall == false)
			verticalWalls[(startingWallPosition.line - 1) / 2][(startingWallPosition.column - 2) / 2].setFillColor(brown);
	}
	if (directionIsHorizontal(direction))
	{
		matrixWhereToAssign[startingWallPosition.line][startingWallPosition.column] = WALL;
		matrixWhereToAssign[startingWallPosition.line][startingWallPosition.column + 1] = WALL;
		matrixWhereToAssign[startingWallPosition.line][startingWallPosition.column + 2] = WALL;
		if (leeCall == false)
			horizontalWalls[(startingWallPosition.line - 2) / 2][(startingWallPosition.column - 1) / 2].setFillColor(brown);
	}
}

void movePawn(int matrixWhereToAssign[NO_LIN_COL + 1][NO_LIN_COL + 1], player &currentPlayer, int whichPlayer, int newLine, int newColumn, bool isAI)
{
	assignFreeCell(matrixWhereToAssign, currentPlayer);

	currentPlayer.position.line = newLine;
	currentPlayer.position.column = newColumn;

	assignUsedCell(matrixWhereToAssign, currentPlayer, whichPlayer, isAI);
}

void copyTwoMatrices(int matrixToBeCopied[NO_LIN_COL + 1][NO_LIN_COL + 1], int matrixWhereToCopy[NO_LIN_COL + 1][NO_LIN_COL + 1])
{
	for (int i = 0; i < NO_LIN_COL - 1; i++)
		for (int j = 0; j < NO_LIN_COL - 1; j++)
			matrixWhereToCopy[i][j] = matrixToBeCopied[i][j];
}

bool leeOnLine(int matrixToCheck[NO_LIN_COL + 1][NO_LIN_COL + 1], player &currentPlayer, int finishLine)
{
	matrixPosition leeQueue[NO_LIN_COL * NO_LIN_COL + 5];
	matrixPosition currentPosition;
	leeQueue[0].line = currentPosition.line = currentPlayer.position.line;
	leeQueue[0].column = currentPosition.column = currentPlayer.position.column;
	int first = 0, last = 0;
	matrixToCheck[currentPlayer.position.line][currentPlayer.position.column] = 1;

	while (currentPosition.line != finishLine && first <= last) {
		currentPosition.line = leeQueue[first].line;
		currentPosition.column = leeQueue[first].column;
		first++;

		for (int i = 0; i < NO_DIRECTIONS; ++i) {
			matrixPosition nextPosition;
			nextPosition.line = currentPosition.line + movementArray[i].line;
			nextPosition.column = currentPosition.column + movementArray[i].column;

			if (matrixToCheck[nextPosition.line][nextPosition.column] != WALL) {
				nextPosition.line += movementArray[i].line;
				nextPosition.column += movementArray[i].column;

				if (matrixToCheck[nextPosition.line][nextPosition.column] == 0) {
					++last;
					leeQueue[last].line = nextPosition.line;
					leeQueue[last].column = nextPosition.column;
					matrixToCheck[nextPosition.line][nextPosition.column] = 1;
				}
				else if (matrixToCheck[nextPosition.line][nextPosition.column] > 1) {
					nextPosition.line += 2 * movementArray[i].line;
					nextPosition.column += 2 * movementArray[i].column;

					if (matrixToCheck[nextPosition.line][nextPosition.column] == 0) {
						++last;
						leeQueue[last].line = nextPosition.line;
						leeQueue[last].column = nextPosition.column;
						matrixToCheck[nextPosition.line][nextPosition.column] = 1;
					}
				}
			}
		}
	}

	if (first > last)
		return false;
	return true;
}

bool leeOnColumn(int matrixToCheck[NO_LIN_COL + 1][NO_LIN_COL + 1], player &currentPlayer, int finishColumn)
{
	matrixPosition leeQueue[NO_LIN_COL * NO_LIN_COL + 5];
	matrixPosition currentPosition;
	leeQueue[0].line = currentPosition.line = currentPlayer.position.line;
	leeQueue[0].column = currentPosition.column = currentPlayer.position.column;
	int first = 0, last = 0;
	matrixToCheck[currentPlayer.position.line][currentPlayer.position.column] = 1;

	while (currentPosition.column != finishColumn && first <= last)
	{
		currentPosition.line = leeQueue[first].line;
		currentPosition.column = leeQueue[first].column;
		first++;

		for (int i = 0; i < NO_DIRECTIONS; ++i) {
			matrixPosition nextPosition;
			nextPosition.line = currentPosition.line + movementArray[i].line;
			nextPosition.column = currentPosition.column + movementArray[i].column;

			if (matrixToCheck[nextPosition.line][nextPosition.column] != WALL) {
				nextPosition.line += movementArray[i].line;
				nextPosition.column += movementArray[i].column;

				if (matrixToCheck[nextPosition.line][nextPosition.column] == 0) {
					++last;
					leeQueue[last].line = nextPosition.line;
					leeQueue[last].column = nextPosition.column;
					matrixToCheck[nextPosition.line][nextPosition.column] = 1;
				}
				else if (matrixToCheck[nextPosition.line][nextPosition.column] > 1) {
					nextPosition.line += 2 * movementArray[i].line;
					nextPosition.column += 2 * movementArray[i].column;

					if (matrixToCheck[nextPosition.line][nextPosition.column] == 0) {
						++last;
						leeQueue[last].line = nextPosition.line;
						leeQueue[last].column = nextPosition.column;
						matrixToCheck[nextPosition.line][nextPosition.column] = 1;
					}
				}
			}
		}
	}

	if (first > last)
		return false;
	return true;
}

int findLength(int matrixToCheck[NO_LIN_COL + 1][NO_LIN_COL + 1], player &currentPlayer, int finishLine, int &nextLine, int &nextColumn)
{
	matrixPosition leeQueue[NO_LIN_COL * NO_LIN_COL + 5];
	matrixPosition currentPosition;
	matrixPosition nextPosition;

	leeQueue[0].line = currentPosition.line = currentPlayer.position.line;
	leeQueue[0].column = currentPosition.column = currentPlayer.position.column;
	int first = 0, last = 0;
	matrixToCheck[currentPlayer.position.line][currentPlayer.position.column] = 1;

	while (first <= last) {
		currentPosition.line = leeQueue[first].line;
		currentPosition.column = leeQueue[first].column;
		first++;

		for (int i = 0; i < NO_DIRECTIONS; ++i) {
			nextPosition.line = currentPosition.line + movementArray[i].line;
			nextPosition.column = currentPosition.column + movementArray[i].column;

			if (matrixToCheck[nextPosition.line][nextPosition.column] == 0) {
				nextPosition.line += movementArray[i].line;
				nextPosition.column += movementArray[i].column;

				if (matrixToCheck[nextPosition.line][nextPosition.column] == 0) {
					++last;
					leeQueue[last].line = nextPosition.line;
					leeQueue[last].column = nextPosition.column;
					matrixToCheck[nextPosition.line][nextPosition.column] = matrixToCheck[currentPosition.line][currentPosition.column] + 1;

					if (nextPosition.line == finishLine)
						goto finish;
				}
				else if (matrixToCheck[nextPosition.line][nextPosition.column] == PAWN) {
					nextPosition.line += 2 * movementArray[i].line;
					nextPosition.column += 2 * movementArray[i].column;

					if ((matrixToCheck[nextPosition.line][nextPosition.column] == 0) && (matrixToCheck[nextPosition.line - movementArray[i].line][nextPosition.column - movementArray[i].column] == 0)) {
						++last;
						leeQueue[last].line = nextPosition.line;
						leeQueue[last].column = nextPosition.column;
						matrixToCheck[nextPosition.line][nextPosition.column] = matrixToCheck[currentPosition.line][currentPosition.column] + 1;

						if (nextPosition.line == finishLine)
							goto finish;
					}
				}
			}
		}
	}

finish:

	nextLine = nextPosition.line;
	nextColumn = nextPosition.column;

	while (matrixToCheck[nextLine][nextColumn] != 2) {
		for (int i = 0; i< NO_DIRECTIONS; i++) {
			int newLine = nextLine + 2 * movementArray[i].line;
			int newColumn = nextColumn + 2 * movementArray[i].column;

			if (newLine >= 0 && newColumn >= 0)
			{
				if (matrixToCheck[newLine][newColumn] == matrixToCheck[nextLine][nextColumn] - 1) {
					nextLine = newLine;
					nextColumn = newColumn;
					break;
				}
				else 
				{
					newLine += 2 * movementArray[i].line;
					newColumn += 2 * movementArray[i].column;

					if (newLine >= 0 && newColumn >= 0)
					{
						if (matrixToCheck[newLine][newColumn] == matrixToCheck[nextLine][nextColumn] - 1) {
							nextLine = newLine;
							nextColumn = newColumn;
							break;
						}
					}
				}
			}
		}
	}

	if (first > last)
		return -1;
	return matrixToCheck[nextPosition.line][nextPosition.column] - 1;
}

void setNeededDataOneVsOne(int matrixWhereToAssign[NO_LIN_COL + 1][NO_LIN_COL + 1], bool whichPlayer)
{
	for (int i = 1; i <= 17; i++)
		for (int j = 1; j <= 17; j++)
			matrixWhereToAssign[i][j] = 0;

	firstPlayer.position.line = 1;
	firstPlayer.position.column = 9;
	firstPlayer.numberOfWallsLeft = secondPlayer.numberOfWallsLeft = 10;
	secondPlayer.position.line = 17;
	secondPlayer.position.column = 9;

	assignUsedCell(matrixWhereToAssign, firstPlayer, whichPlayer, 0);
	assignUsedCell(matrixWhereToAssign, secondPlayer, !whichPlayer, 0);
}

void setNeededDataFourPlayers(int matrixWhereToAssign[NO_LIN_COL + 1][NO_LIN_COL + 1], int whichPlayer)
{
	for (int i = 1; i <= 17; i++)
		for (int j = 1; j <= 17; j++)
			matrixWhereToAssign[i][j] = 0;

	firstPlayer.position.line = 1;
	firstPlayer.position.column = 9;
	secondPlayer.position.line = 17;
	secondPlayer.position.column = 9;
	thirdPlayer.position.line = 9;
	thirdPlayer.position.column = 1;
	fourthPlayer.position.line = 9;
	fourthPlayer.position.column = 17;

	firstPlayer.numberOfWallsLeft = secondPlayer.numberOfWallsLeft = thirdPlayer.numberOfWallsLeft = fourthPlayer.numberOfWallsLeft = 8;

	assignUsedCell(matrixWhereToAssign, firstPlayer, 1, 0);
	assignUsedCell(matrixWhereToAssign, secondPlayer, 0, 0);
	assignUsedCell(matrixWhereToAssign, thirdPlayer, 2, 0);
	assignUsedCell(matrixWhereToAssign, fourthPlayer, 3, 0);
}

void setNeededDataVsAI(int matrixWhereToAssign[NO_LIN_COL + 1][NO_LIN_COL + 1], int whichPlayer)
{
	for (int i = 1; i <= 17; i++)
		for (int j = 1; j <= 17; j++)
			matrixWhereToAssign[i][j] = 0;

	AI.position.line = 1;
	AI.position.column = 9;
	AI.numberOfWallsLeft = secondPlayer.numberOfWallsLeft = 10;
	secondPlayer.position.line = 17;
	secondPlayer.position.column = 9;

	assignUsedCell(matrixWhereToAssign, secondPlayer, whichPlayer, 1);
	assignUsedCell(matrixWhereToAssign, AI, !whichPlayer, 1);
}

void copyTwoRectangles(sf::RectangleShape whereToCopy[10][10], sf::RectangleShape whatToCopy[10][10])
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			whereToCopy[i][j] = whatToCopy[i][j];
}
