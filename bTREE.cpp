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

int bTREE::numberOfNodesH(treeNode *leaf)
{
	int count = 1;
	// If tree is empty
	if (leaf == NULL)
		return 0;
	else
	{
		// Recursively count nodes on left and right sides
		count = count + numberOfNodesH(leaf->right);
		count = count + numberOfNodesH(leaf->left);
		return count;
	}
}

int bTREE::numberOfNodes()
{
	// Calls helper function
	numberOfNodesH(root);
}

int bTREE::insert(treeNode *node, string dat, int tim)
{
	// Create a node containing the data that is to be added
	treeNode *node;
	node->data = dat;
	node->time = tim;
	// If tree is empty, make new node the root
	if (root == NULL)
		root = node;
	else
	{
		// 
		if (dat > root->data)
			return insert(root->right, dat, tim);
		else
			return insert(root->left, dat, tim);
	}
}

int bTREE::find(treeNode *node, string dat)
{
	// 1 operation if tree is empty
	if (node == NULL)
		return 1;

	int sizeL, sizeR = 0;
	// Check if data is found
	if (dat == node->data)
		// Return number of operations if data is found
		return (sizeL + sizeR + 1);
	else
	{
		// If data is not yet found, recurse
		sizeL = find(node->left, dat);
		sizeR = find(node->right, dat);
	}
	//If data is not found in tree, return number of operations performed
	return (sizeL + sizeR + 1);
}

string bTREE::locate(treeNode *node, string dat)
{
	string seq = "";
	if (node == NULL)
		return "Empty tree";
	if(dat == node->data)
	{

		return seq;
	}

}

void bTREE::displayLeft(std::ostream& outfile, treeNode *subtree, string prefix)
{
	if (subtree == NULL)
		outfile << prefix + "/" << std::endl;
	else
	{
		displayLeft(outfile, subtree->left, prefix + "     ");
		outfile << prefix + "/---" << "(" << subtree->data <<", " << subtree->time << ")" << std::endl;
		displayRight(outfile, subtree->right, prefix + "|    ");
	}
}

void bTREE::displayRight(std::ostream& outfile, treeNode *subtree, string prefix)
{
	if (subtree == NULL)
		outfile << prefix + "\\" << std::endl;
	else
	{
		displayLeft(outfile, subtree->left, prefix + "|    ");
		outfile << prefix + "\\---" << "(" << subtree->data << ", " << subtree->time << ")" << std::endl;
		displayRight(outfile, subtree->right, prefix + "     ");
	}
}

void bTREE::display(std::ostream& outfile)
{
	std::string prefix;
	if (root == NULL)
		outfile << "Empty tree" << std::endl;
	else
	{
		displayLeft(outfile, root->left, "     ");
		outfile << "---" << "(" << root->data << ", " << root->time << ")" << std::endl;
		displayRight(outfile, root->right, "     ");
	}
}

bool operator ==(bTREE& lhs, bTREE& rhs)
{
	// If the sizes of the trees are different, they are not equal
	if (lhs.numberOfNodes() != rhs.numberOfNodes())
		return false;
	else
	{
		// If the contents and locations are the same, the trees are equal
		if (lhs == rhs) //&& (lhs->left == rhs->left) && (lhs->right == rhs->right))
			return true;
		else
			 false;
	}
}

bool operator != (bTREE& lhs, bTREE& rhs)
{
	// If the sizes of the trees are different, they are not equal
	if (lhs.numberOfNodes() != rhs.numberOfNodes())
		return true;
	else
	{
		// If the contents and locations are the same, the trees are equal
		if (lhs != rhs) //&& (lhs->left == rhs->left) && (lhs->right == rhs->right))
			return true;
		else
			return false;
	}
}

std::ostream& operator <<(std::ostream& out, const bTREE& p)
{
	return out;
}
