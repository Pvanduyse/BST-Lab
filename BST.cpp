#include "BST.h"

bool BST::setRootNode(Node* root)
{
	this->root = root;
	if(root != NULL)
		root->setParent(NULL);
	return true;
}

//Functionally the same as the alternative, but subjectively harder to read
/*Node* BST::find(const int &data, Node* thisNode) const
{
	if(thisNode == NULL || data == thisNode->getData())
		return thisNode;

	Node* candidate = ((data < thisNode->getData()) ?
		find(data, thisNode->getLeftChild()) : find(data, thisNode->getRightChild()));
		
	return ((candidate == NULL) ? thisNode : candidate);
}*/

Node* BST::find(const int &data, Node* thisNode) const
{
	if(thisNode == NULL || data == thisNode->getData())
		return thisNode;

	Node* candidate;
	if(data < thisNode->getData())
		candidate = find(data, thisNode->getLeftChild());
	else
		candidate = find(data, thisNode->getRightChild());

	if(candidate == NULL)
		return thisNode;
	return candidate;
}

Node* BST::getRootNode() const
{
	return root;
}

bool BST::add(int data)
{
	if(root == NULL)
		return setRootNode(new Node(data));

	Node* parent = find(data, root);

	if(data < parent->getData())
		return parent->setLeftChild(new Node(data));

	if(data > parent->getData())
		return parent->setRightChild(new Node(data));

	//if(data == parent->getData()) // check not needed
	return false;
}

bool BST::remove(int data)
{
	Node* thisNode = find(data, root); // returns
	if(thisNode->getData() != data)
		return false;

	return remove(thisNode);
}

bool BST::remove(Node* thisNode)
{
	// If this node has two children, find the node immediately smaller than thisNode
	// Copy it's value over to thisNode
	if(thisNode->getLeftChild() != NULL && thisNode->getRightChild() != NULL)
	{
		// iterate to the node immediately smaller than thisNode
		Node* replace;
		for(replace = thisNode->getLeftChild(); replace->getRightChild() != NULL; replace = replace->getRightChild());
		thisNode->setData(replace->getData());
		thisNode = replace;
	}

	Node* replace = NULL;

	if(thisNode->getLeftChild() != NULL)
		replace = thisNode->getLeftChild();

	if(thisNode->getRightChild() != NULL)
		replace = thisNode->getRightChild();

	Node* parent = thisNode->getParent();

	delete thisNode;

	// unlink and deallocate the node
	if(parent == NULL)
		return setRootNode(replace);

	if(parent->getLeftChild() == thisNode)
		return parent->setLeftChild(replace);

	if(parent->getRightChild() == thisNode)
		return parent->setRightChild(replace);

	throw runtime_error("BST incorrectly linked. Node not a child of parent.");
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
	if(thisNode->getLeftChild() != NULL)
		clear(thisNode->getLeftChild());

	if(thisNode->getRightChild() != NULL)
		clear(thisNode->getRightChild());

	delete thisNode;
	return;
}
