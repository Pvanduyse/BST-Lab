#include "NodeInterface.h"

class Node : public NodeInterface
{
protected:
	int data;
	Node* parent = NULL;
	Node* leftChild = NULL;
	Node* rightChild = NULL;

public:
	Node(int data) { setData(data); }
	~Node() {}

	int getData() const { return data; }

	Node* getParent() const { return parent; }

	Node* getLeftChild() const { return leftChild; }

	Node* getRightChild() const { return rightChild; }

	void setData(int data) { this->data = data; }

	void setParent(Node* parent) { this->parent = parent; }

	bool setLeftChild(Node* leftChild);

	bool setRightChild(Node* rightChild);
};
