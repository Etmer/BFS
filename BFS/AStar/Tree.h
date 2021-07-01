#pragma once

namespace AStar
{
	class Tree
	{
	private:
		void Solve(Board& const board, Board& const solution);
		bool ListContains(Node& node, std::vector<Node*>& list, Node*& duplicateIndex);
		bool IsNodeSolved(Node& node, const Board& solution);
		std::vector<Node*> MakeChildren(Board& const board);
		void CreatePath(Node* lhs, Node* rhs);
	public:
		Tree(Board& const board, Board& const solution);
		~Tree();
	};
}

