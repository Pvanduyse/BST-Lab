#pragma once

#include "BSTInterface.h"

using namespace std;

class BST : public BSTInterface
{
protected:
	class Node : public NodeInterface
	{
	public:
		Node(int data) { this->data = data; }
		~Node() {}

		int getData() const { return data; }

		Node* getParent() const { return parent; }

		Node* getLeftChild() const { return leftChild; }

		Node* getRightChild() const { return rightChild; }

		void setData(int data) { this->data = data; }

		void setParent(Node* parent) { this->parent = parent; }

		void setLeftChild(Node* leftChild)
		{
			this->leftChild = leftChild;
			if(leftChild != NULL)
				leftChild->setParent(this);
		}

		void setRightChild(Node* rightChild)
		{
			this->rightChild = rightChild;
			if(rightChild != NULL)
				rightChild->setParent(this);
		}

	private:
		int data;
		Node* parent = NULL;
		Node* leftChild = NULL;
		Node* rightChild = NULL;
	};// end of Node definition

	Node* root = NULL;

	void setRoot(Node* root)
	{
		this->root = root;
		if(root != NULL)
			root->setParent(NULL);
	}

	Node* find(int data);

	Node* find(int data, Node* thisNode);

	bool remove(Node* thisNode);

	void clear(Node* thisNode);

public:
	BST() {}
	~BST() { clear(); }

	NodeInterface* getRootNode() const { return root; }

	bool add(int data);

	bool remove(int data);

	void clear();
};
