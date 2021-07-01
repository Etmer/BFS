#include "AStarTree.h"
#include <vector>
#include <list>
#include <stack>
#include <iostream>
#include <algorithm>

namespace Algorithm
{
	namespace AStar
	{
		AStarTree::AStarTree(Board& const board, Board& const solution)
		{
			Solve(board, solution);
		}

		AStarTree::~AStarTree()
		{
		}

		void AStarTree::Solve(Board& const board, Board& const solution)
		{
			bool solved = false;
			AStarNode* startNode = new AStarNode(&board);
			AStarNode* endNode = new AStarNode(&solution);

			std::vector<AStarNode*> openList = { startNode };
			std::vector<AStarNode*> closedList;

			std::vector<AStarNode*> openListReversed = { endNode };
			std::vector<AStarNode*> closedListReversed;

			while (openList.size() > 0 && openListReversed.size() > 0 && !solved)
			{
				AStarNode* current = openList.front();
				AStarNode* currentReversed = openListReversed.front();

				closedList.push_back(current);
				closedListReversed.push_back(currentReversed);

				openList.erase(openList.begin());
				openListReversed.erase(openListReversed.begin());

				std::vector<AStarNode*> children = MakeChildren(*(current->GetData()));

				for (AStarNode* const node : children)
				{
					AStarNode* duplicate = nullptr;
					if (!ListContains(*node, closedList, duplicate))
					{
						current->AddChild(node);
						openList.push_back(node);

					}
					else
						delete node;
				}

				std::vector<AStarNode*> childrenRevesed = MakeChildren(*(currentReversed->GetData()));

				for (AStarNode* const node : childrenRevesed)
				{
					AStarNode* duplicate = nullptr;
					if (!ListContains(*node, closedListReversed, duplicate))
					{
						currentReversed->AddChild(node);
						openListReversed.push_back(node);

						if (ListContains(*node, closedList, duplicate))
						{
							std::cout << "Connected" << std::endl;
							CreatePath(node, duplicate);
							solved = true;
						}
					}
					else
						delete node;
				}

				std::sort(openList.begin(), openList.end(), [](const Algorithm::AStar::AStarNode* lhs, const Algorithm::AStar::AStarNode* rhs) {return lhs->cost < rhs->cost; });
				std::sort(openListReversed.begin(), openListReversed.end(), [](const Algorithm::AStar::AStarNode* lhs, const Algorithm::AStar::AStarNode* rhs) {return lhs->cost < rhs->cost; });
			}

			delete startNode;
			delete endNode;
		}

		bool AStarTree::ListContains(AStarNode& node, std::vector<AStarNode*>& list, AStarNode*& duplicateIndex)
		{
			for (int i = 0; i < list.size(); i++)
			{
				AStarNode* closedNode = list.at(i);
				if (node == *(closedNode))
				{
					duplicateIndex = closedNode;
					return true;
				}
			}
			return false;
		}

		bool AStarTree::IsNodeSolved(AStarNode& node, const Board& solution)
		{
			Board* current = node.GetData();

			bool result = *current == solution;

			if (result)
				current->Draw();

			return result;
		}

		std::vector<AStarNode*> AStarTree::MakeChildren(Board& const board)
		{
			std::vector<AStarNode*> result;
			for (int i = 0; i < 4; i++)
			{
				Board newBoard = Board(board);

				switch (i)
				{
				case 0:
					if (newBoard.MoveDown())
						result.push_back(new AStarNode(&newBoard));
					break;
				case 1:
					if (newBoard.MoveUp())
						result.push_back(new AStarNode(&newBoard));
					break;
				case 2:
					if (newBoard.MoveLeft())
						result.push_back(new AStarNode(&newBoard));
					break;
				case 3:
					if (newBoard.MoveRight())
						result.push_back(new AStarNode(&newBoard));
					break;
				}
			}
			return result;
		}


		void AStarTree::CreatePath(AStarNode* lhs, AStarNode* rhs)
		{
			std::list<AStarNode*> lhsPath;

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

			for (AStarNode* elem : lhsPath)
			{
				elem->GetData()->Draw();
			}
		}
	}
}