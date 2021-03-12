#include "Node.h"

bool Node::setLeftChild(Node* leftChild)
{
	this->leftChild = leftChild;
	if(leftChild != NULL)
		leftChild->setParent(this);
	return true;
}

bool Node::setRightChild(Node* rightChild)
{
	this->rightChild = rightChild;
	if(rightChild != NULL)
		rightChild->setParent(this);
	return true;
}
