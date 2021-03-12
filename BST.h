#pragma once

#include "BSTInterface.h"
#include "Node.h"

using namespace std;

class BST : public BSTInterface
{
protected:
	Node* root = NULL;

	bool setRootNode(Node* root);

	Node* find(const int &data, Node* thisNode) const;

	bool remove(Node* thisNode);

	void clear(Node* thisNode);

public:
	BST() {}
	~BST() { clear(); }

	Node* getRootNode() const;

	bool add(int data);

	bool remove(int data);

	void clear();
};
