#pragma once
#include<vector>
#include "Board.h";

class Node
{
private:
	Node* parent = nullptr;
	std::vector<Node*> children;
	Board* data = nullptr;
	unsigned int nodeIndex = 0;
public:
	Node(Board* const data);
	~Node();
	Board* GetData();
	void SetParent(Node* const parent);
	Node* GetParent();
	void AddChild(Node* const child);
	bool operator==(const Node& other);
	bool operator!=(const Node& other);
};

