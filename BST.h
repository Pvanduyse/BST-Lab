#pragma once

#include "BSTInterface.h"
#include "Node.h"

using namespace std;

class BST : public BSTInterface
{

public:
	BST() {}
	~BST() { clear(); }

	Node* getRootNode() const;

	bool add(int data);

	bool remove(int data);

	void clear();

protected:
	bool setRootNode(Node* root);

	Node* find(const int &data, Node* thisNode) const;

private:
	Node* root = NULL;

	void clear(Node* thisNode);
};
