#include "Board.h"
#include <iostream>
#include <vector>
#include "Node.h"


int Board::CalcIndexFromPosition(int x, int y)
{
	return (x * sizeY) + y;
}

void Board::CalcPositionFromIndex(int index, int& x, int& y) 
{
	x = index / sizeY;
	y = index % sizeY;
}

Board::Board(const Board& other)
{
	this->sizeX = other.sizeX;
	this->sizeY = other.sizeY;

	currentEmptyIndex = other.currentEmptyIndex;
	values = new int* [sizeX];

	for (int x = 0; x < sizeX; x++)
	{
		values[x] = new int[sizeY];
		for (int y = 0; y < sizeY; y++)
		{
			int index = other.values[x][y];
			values[x][y] = index;
			length++;
		}
	}
}

Board::Board(int sizeX, int sizeY) 
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;

	values = new int*[sizeX];

	for (int x = 0; x < sizeX; x++) 
	{
		values[x] = new int[sizeY];
		for (int y = 0; y < sizeY; y++) 
		{
			int index = CalcIndexFromPosition(x, y);
			values[x][y] = index;
			length++;
		}
	}
}

Board::~Board() 
{
	for (int x = 0; x < sizeX; x++) 
	{
		delete[] values[x];
	}
	delete[] values;
}

int Board::GetValue(int x, int y) { return values[x][y]; }

void Board::Shuffle(int iterations)
{
	for (int i = 0; i < iterations; i++) 
	{
		int random = rand() % 4;

		switch (random)
		{
		case 0:
			MoveUp();
			break;
		case 1:
			MoveDown();
			break;
		case 2:
			MoveRight();
			break;
		case 3:
			MoveLeft();
			break;
		}
	}
}

void Board::Draw() 
{
	for (int x = 0; x < sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			int index = CalcIndexFromPosition(x, y);
			std::cout << "[" << GetValue(x,y) << "]";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool Board::MoveUp() 
{
	return MovePiece(-1,0);
}

bool Board::MoveDown() 
{
	return MovePiece(1,0);
}

bool Board::MoveRight() 
{
	return MovePiece(0, 1);
}

bool Board::MoveLeft()
{
	return MovePiece(0, -1);
}

bool Board::MovePiece(int x, int y) 
{
	int origin = currentEmptyIndex;

	int column = (origin % sizeY) + y;
	int row = (origin / sizeY) + x;

	int next = CalcIndexFromPosition(row, column);

	if (IsPositionValid(row, column))
	{	
		SwapValues(next, origin);
		currentEmptyIndex = next;
		return true;
	}
	return false;
}

bool Board::IsPositionValid(int x, int y) 
{
	bool rowValid = x >= 0 && x < sizeX;
	bool columnValid = y >= 0 && y < sizeY;

	return columnValid && rowValid;
}


void Board::SwapValues(int origin, int next)
{
	int originX = 0;
	int originY = 0;

	CalcPositionFromIndex(origin, originX, originY);

	int nextX = 0;
	int nextY = 0;

	CalcPositionFromIndex(next, nextX, nextY);

	int lhs = values[originX][originY];
	int rhs = values[nextX][nextY];

	values[originX][originY] = rhs;
	values[nextX][nextY] = lhs;
}


int Board::GetSizeX() { return sizeX; }

int Board::GetSizeY() { return sizeY; }

bool Board::operator==(const Board& other) 
{
	for (int x = 0; x < GetSizeX(); x++)
	{
		for (int y = 0; y < GetSizeY(); y++)
		{
			if (other.values[x][y] != GetValue(x, y))
				return false;
		}
	}
}

bool Board::operator!=(const Board& other) 
{
	return !operator==(other);
}

