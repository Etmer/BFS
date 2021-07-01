#include "Node.h"
#include <iostream>

namespace Algorithm
{
	namespace BreadthFirst
	{
		Node::Node(Board* const data)
		{
			this->data = new Board(*data);
		}

		Node::~Node()
		{
			delete data;

			for (Node* node : children)
				delete node;
		}

		void Node::AddChild(Node* const child)
		{
			child->SetParent(this);
			children.push_back(child);
		}

		void Node::SetParent(Node* const parent) { this->parent = parent; }

		Node* Node::GetParent() { return parent; }


		Board* Node::GetData() { return data; }

		bool Node::operator==(const Node& other)
		{
			return *other.data == *data;
		}

		bool Node::operator!=(const Node& other)
		{
			return !operator==(other);
		}
	}
}