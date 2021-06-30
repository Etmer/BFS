#include "Tree.h"
#include <vector>
#include <list>
#include <stack>
#include <iostream>

Tree::Tree(Board& const board, Board& const solution)
{
	Solve(board, solution);
}

Tree::~Tree() 
{
}

void Tree::Solve(Board& const board, Board& const solution)
{
	bool solved = false;
	Node* startNode = new Node(&board);
	Node*  endNode = new Node(&solution);

	std::vector<Node*> openList = { startNode };
	std::vector<Node*> closedList;

	std::vector<Node*> openListReversed = { endNode };
	std::vector<Node*> closedListReversed;

	while (openList.size() > 0 && openListReversed.size() > 0 && !solved) 
	{
		Node* current = openList.front();
		Node* currentReversed = openListReversed.front();

		closedList.push_back(current);
		closedListReversed.push_back(currentReversed);

		openList.erase(openList.begin());
		openListReversed.erase(openListReversed.begin());

		std::vector<Node*> children = MakeChildren(*(current->GetData()));

		for (Node* const node : children) 
		{
			int duplicate = 0;
			if (!ListContains(*node, closedList, duplicate))
			{
				current->AddChild(node);
				openList.push_back(node);

			}
			else 
				delete node;
		}	
		
		std::vector<Node*> childrenRevesed = MakeChildren(*(currentReversed->GetData()));

		for (Node* const node : childrenRevesed)
		{
			int duplicate = 0;
			if (!ListContains(*node, closedListReversed, duplicate))
			{
				currentReversed->AddChild(node);
				openListReversed.push_back(node);

				if (ListContains(*node, closedList, duplicate))
				{
					ListContains(*node, closedList, duplicate);
					std::cout << "Connected" << std::endl;
					CreatePath(node, closedList.at(duplicate));
					solved = true;
				}
			}
			else
				delete node;
		}
	}

	delete startNode;
	delete endNode;
}

bool Tree::ListContains(Node& node, std::vector<Node*>& list, int& duplicateIndex)
{
	for(int i = 0; i < list.size(); i++)
	{
		Node* closedNode = list.at(i);
		if (node == *(closedNode))
		{
			duplicateIndex = i;
			return true;
		}
	}
	return false;
}

bool Tree::IsNodeSolved(Node& node, const Board& solution)
{
	Board* current = node.GetData();

	bool result = *current == solution;

	if (result)
		current->Draw();

	return result;
}

std::vector<Node*> Tree::MakeChildren(Board& const board)
{
	std::vector<Node*> result;
	for (int i = 0; i < 4; i++)
	{
		Board newBoard = Board(board);

		switch (i)
		{
		case 0:
			if (newBoard.MoveDown())
				result.push_back(new Node(&newBoard));
			break;
		case 1:
			if (newBoard.MoveUp())
				result.push_back(new Node(&newBoard));
			break;
		case 2:
			if (newBoard.MoveLeft())
				result.push_back(new Node(&newBoard));
			break;
		case 3:
			if (newBoard.MoveRight())
				result.push_back(new Node(&newBoard));
			break;
		}
	}
	return result;
}


void Tree::CreatePath(Node* lhs, Node* rhs) 
{
	std::list<Node*> lhsPath;

	while (lhs) 
	{
		lhsPath.push_back(lhs);
		lhs = lhs->GetParent();
	}

	rhs = rhs->GetParent();

	while (rhs)
	{
		lhsPath.push_front(rhs);
		rhs = rhs->GetParent();
	}

	for (Node* elem : lhsPath) 
	{
		elem->GetData()->Draw();
	}
}