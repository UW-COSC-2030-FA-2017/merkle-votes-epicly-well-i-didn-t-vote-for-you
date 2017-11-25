#include "bTREE.h"


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
	root = NULL;
}

bTREE::~bTREE()
{
}

int bTREE::dataInserted()
{
}

int bTREE::numberOfNodes(treeNode *leaf)
{
	int count = 1;
	// If tree is empty
	if (leaf == NULL)
		return 0;
	else
	{
		// Recursively count nodes on left and right sides
		count = count + numberOfNodes(leaf->right);
		count = count + numberOfNodes(leaf->left);
		return count;
	}
}

int bTREE::insert(string data, int time)
{
	// Create a node containing the data that is to be added
	treeNode node;
	node.data = data;
	node.time = time;

}

int bTREE::find(string)
{
}

string bTREE::locate(string)
{
}

friend bool bTREE::operator ==(const bTREE& lhs, const bTREE& rhs)
{
	// If the sizes of the trees are different, they are not equal
	if (numberOfNodes(lhs) != numberOfNodes(rhs))
		return false;
	else
	{
		// If the contents and locations are the same, the trees are equal
		if ((lhs->data == rhs->data) && (lhs->left == rhs->left) && (lhs->right == rhs->right))
			return true;
		else
			return false;
	}
}

friend bool bTREE::operator !=(const bTREE& lhs, const bTREE& rhs)
{
	// If the sizes of the trees are different, they are not equal
	if (numberOfNodes(lhs) != numberOfNodes(rhs))
		return true;
	else
	{
		// If the contents and locations are the same, the trees are equal
		if ((lhs->data == rhs->data) && (lhs->left == rhs->left) && (lhs->right == rhs->right))
			return false;
		else
			return true;
	}
}

friend std::ostream& bTREE::operator <<(std::ostream& out, const bTREE& p)
{
}
