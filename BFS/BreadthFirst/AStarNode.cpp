#include "AStarNode.h"
#include <iostream>

namespace Algorithm
{
	namespace AStar
	{
		AStarNode::AStarNode(Board* const data)
		{
			this->data = new Board(*data);

			for (int x = 0; x < data->GetSizeX(); x++)
			{
				for (int y = 0; y < data->GetSizeY(); y++)
				{
					int index = data->GetValue( x, y); 

					int targetX = 0;
					int targetY = 0;

					data->CalcPositionFromIndex(index, targetX, targetY);

					cost += abs(targetX-x) + (abs(targetY-y));
				}
			}
		}

		AStarNode::~AStarNode()
		{
			delete data;

			for (AStarNode* node : children)
				delete node;
		}

		void AStarNode::AddChild(AStarNode* const child)
		{
			child->SetParent(this);
			children.push_back(child);
		}

		void AStarNode::SetParent(AStarNode* const parent) { this->parent = parent; }

		AStarNode* AStarNode::GetParent() { return parent; }


		Board* AStarNode::GetData() { return data; }

		bool AStarNode::operator==(const AStarNode& other)
		{
			return *other.data == *data;
		}

		bool AStarNode::operator!=(const AStarNode& other)
		{
			return !operator==(other);
		}

	}
}