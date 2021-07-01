#pragma once
#include "AStarNode.h"

namespace Algorithm
{
	namespace AStar
	{
		class AStarTree
		{
		private:
			void Solve(Board& const board, Board& const solution);
			bool ListContains(AStarNode& node, std::vector<AStarNode*>& list, AStarNode*& duplicateIndex);
			bool IsNodeSolved(AStarNode& node, const Board& solution);
			std::vector<AStarNode*> MakeChildren(Board& const board);
			void CreatePath(AStarNode* lhs, AStarNode* rhs);
		public:
			AStarTree(Board& const board, Board& const solution);
			~AStarTree();
		};
	}
}
