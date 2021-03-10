#include "BST.h"

BST::Node* BST::find(int data)
{
	return find(data, root);
}

BST::Node* BST::find(int data, Node* thisNode)
{
	if(thisNode == NULL)
		return NULL;

	int thisData = thisNode->getData();
	Node* candidate = thisNode;

	if(data < thisData)
	{
		candidate = find(data, thisNode->getLeftChild());
		if(candidate == NULL)
			candidate = thisNode;
	}

	if(data > thisData)
	{
		candidate = find(data, thisNode->getRightChild());
		if(candidate == NULL)
			candidate = thisNode;
	}

	return candidate;
}

bool BST::add(int data)
{
	if(root == NULL)
	{
		setRoot(new Node(data));
		return true;
	}

	Node* parentNode = find(data);

	if(data < parentNode->getData())
	{
		parentNode->setLeftChild(new Node(data));
		return true;
	}

	if(data > parentNode->getData())
	{
		parentNode->setRightChild(new Node(data));
		return true;
	}

	return false;
}

bool BST::remove(int data)
{
	Node* thisNode = find(data);
	if(thisNode->getData() != data)
		return false;

	return remove(thisNode);
}

bool BST::remove(Node* thisNode)
{
	Node* parent = thisNode->getParent();
	Node* replace = NULL;

	if(thisNode->getLeftChild() != NULL && thisNode->getRightChild() != NULL)
	{
		// iterate to the node immediately smaller than thisNode
		for(replace = thisNode->getLeftChild(); replace->getRightChild() != NULL; replace = replace->getRightChild());
		thisNode->setData(replace->getData());
		return remove(replace);
	}

	if(thisNode->getLeftChild() != NULL)
		replace = thisNode->getLeftChild();

	if(thisNode->getRightChild() != NULL)
		replace = thisNode->getRightChild();

	// unlink and deallocate the node
	if(parent == NULL)
		setRoot(replace);

	if(parent != NULL && parent->getLeftChild() == thisNode)
		parent->setLeftChild(replace);

	if(parent != NULL && parent->getRightChild() == thisNode)
		parent->setRightChild(replace);

	delete thisNode;
	return true;
}

void BST::clear()
{
	if(root != NULL)
	{
		clear(root);
		root = NULL;
	}
	return;
}

void BST::clear(Node* thisNode)
{
	Node* leftChild = thisNode->getLeftChild();
	if(leftChild != NULL)
		clear(leftChild);

	Node* rightChild = thisNode->getRightChild();
	if(rightChild != NULL)
		clear(rightChild);

	delete thisNode;
	return;
}
