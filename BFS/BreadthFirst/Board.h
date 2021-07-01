#pragma once

namespace Algorithm
{
	class Board
	{
	private:
		int** values;
		int sizeX = 0;
		int sizeY = 0;
		int length = 0;
		int currentEmptyIndex = 0;
		bool IsPositionValid(int x, int y);
		void SwapValues(int lhs, int rhs);
		bool MovePiece(int x, int y);

	public:
		int CalcIndexFromPosition(int x, int y);
		void CalcPositionFromIndex(int index, int& x, int& y);
		Board(int sizeX, int sizeY);
		Board(const Board&);
		~Board();

		int GetSizeX();
		int GetSizeY();

		int GetValue(int x, int y);
		void Shuffle(int iteations);
		bool MoveUp();
		bool MoveDown();
		bool MoveRight();
		bool MoveLeft();
		void Draw();

		bool operator==(const Board&);
		bool operator!=(const Board&);
	};

}