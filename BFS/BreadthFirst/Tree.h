#pragma once
#include "Node.h"

class Tree
{
private:
	void Solve(Board& const board, Board& const solution);
	bool ListContains(Node& node, std::vector<Node*>& list, int& duplicateIndex);
	bool IsNodeSolved(Node& node, const Board& solution);
	std::vector<Node*> MakeChildren(Board& const board);
	void CreatePath(Node* lhs, Node* rhs);
public:
	Tree(Board& const board, Board& const solution);
	~Tree();
};

