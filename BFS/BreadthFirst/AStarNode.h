#pragma once
#include <vector>
#include "Board.h";

namespace Algorithm 
{
	namespace AStar 
	{
		class AStarNode
		{
		private:
			AStarNode* parent = nullptr;
			std::vector<AStarNode*> children;
			Board* data = nullptr;
			unsigned int nodeIndex = 0;
		public:
			int cost = 0;
			AStarNode(Board* const data);
			~AStarNode();
			Board* GetData();
			void SetParent(AStarNode* const parent);
			AStarNode* GetParent();
			void AddChild(AStarNode* const child);
			bool operator==(const AStarNode& other);
			bool operator!=(const AStarNode& other);
		};
	}
}