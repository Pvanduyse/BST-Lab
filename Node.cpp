#include "Node.h"

void Node::setParent(Node* parent)
{
	if(parent != NULL && parent->getLeftChild() != this && parent->getRightChild() != this)
		throw std::runtime_error("Cannot set parent if this is not set as child of parent");

	this->parent = parent;
}

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
