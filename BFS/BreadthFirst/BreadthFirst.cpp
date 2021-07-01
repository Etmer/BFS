// BreadthFirst.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include "Tree.h"
#include "Board.h"
#include "AStarTree.h"
#include <list>
#include <algorithm>

void StartBreadthFirst();
void StartAStar();
int main()
{
	int input;

	std::cout << "########## BFS ##########" << std::endl;
	StartBreadthFirst();
	std::cout << std::endl;

	std::cin >> input;
	std::cout << std::endl;


	std::cout << "########## A* ##########" << std::endl;
	StartAStar();
	std::cout << std::endl;
}

void StartBreadthFirst() 
{
	Algorithm::Board board = Algorithm::Board(3, 3);
	Algorithm::Board solution = Algorithm::Board(3, 3);
	board.Shuffle(13230);
	board.Draw();
	std::cout << std::endl;

	Algorithm::BreadthFirst::Tree tree = Algorithm::BreadthFirst::Tree(board, solution);
	int i = 0;
}
void StartAStar()
{
	Algorithm::Board board = Algorithm::Board(3, 3);
	Algorithm::Board solution = Algorithm::Board(3, 3);
	board.Shuffle(13230);

	Algorithm::AStar::AStarTree tree = Algorithm::AStar::AStarTree(board, solution);
	int i = 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
