#include "pMT.h"
#include "bTREE.h"

pMT::pMT(int hashSelect)
/**
* @brief
* @param hashSelect a number corresponding to the hashfunction to use for this pMT
* @return
*/
{
	selectedHash = hashSelect;
}

pMT::~pMT()
/**
* @brief destructor
* @return nada
*/
{
}

string pMT::hashS(string data)
{
	switch (selectedHash) {
	case 1: return hash_1(data);
		break;
	case 2: return hash_2(data);
		break;
	case 3: return hash_3(data);
		break;
	default: return "---";
	}
}

int pMT::insert(treeNode *node, string vote, int tim)
/**
* @brief insert a vote and time into a leaf node of tree
* @param vote - a string
* @param time - an int representing the time
* @return the number of operations needed to do the insert, -1 if out of memory
*/
{
	// Create a node containing the data that is to be added
	node->data = vote;
	node->time = tim;
	// If tree is empty, make new node the root
	if (root == NULL)
		root = node;
	else
	{
		// Checks if the data is larger or smaller than tree's current contents
		if (vote > root->data) {
			// If larger, insert to the right
			hashS(node->data);
			return insert(root->right, vote, tim);
		}
		else {
			// If smaller, insert to the left
			hashS(node->data);
			return insert(root->left, vote, tim);
		}
	}
}

int pMT::find(treeNode *node, string vote, int tim, int hashSelect)
/**
* @brief given a vote, timestamp, and hash function, does this vote exist in the tree?
* @param vote, a string
* @param time, an int
* @param hashSelect, an int corresponding to the hash functions _1, _2, and _3
* @return 0 if not found, else number of opperations required to find the matching vote
*/
{
	// If node is empty, tree contains no data
	if (node == NULL)
		return 1;

	int sizeL, sizeR;
	// Check if data is found
	if (node->data == vote && node->time == tim && hashSelect == selectedHash)
		return (sizeL + sizeR + 1);
	else
	{
		// If data is not yet found, recurse
		sizeL = find(node->left, vote, tim, hashSelect);
		sizeR = find(node->right, vote, tim, hashSelect);
	}
	// If data is not found in tree, return number of operations performed
	return (sizeL + sizeR + 1);
}

int pMT::findHash(string mhash)
/**
* @brief does this hash exist in the tree?
* @param mhash, a string to search for in the tree
* @return 0 if not found, else number of opperations required to find the matching hash
*/
{
	return findHashH(mhash, root);
}

int pMT::findHashH(string mhash, treeNode *node)
{
	if (node == NULL)
	{
		return 0;
	}
	else if (node->data == mhash)
	{
		return 1;
	}
	else
	{
		int Left, Right;
		Left = findHashH(mhash, node->left);
		Right = findHashH(mhash, node->right);
		if (Left > Right)
		{
			return Left + 1;
		}
		else if (Right > Left)
		{
			return Right + 1;
		}
		else
		{
			return 0;
		}
	}
}

string pMT::locateData(string vote)
/**
* @brief Function takes a hash of Vote and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root.
* @param vote, the data to search for
* @return sequence of L's and R's comprising the movement to the leaf node; else return a dot '.'
*/
{
	locateDataH(vote, root);
}

string pMT::locateDataH(string vote, treeNode *node)
{
	if (node = NULL)
	{
		return ".";
	}
	else if (node->left->data == vote)
	{
		return "left ";
	}
	else if (node->right->data == vote)
	{
		return "right ";
	}
	else
	{
		string stringL, stringR;
		stringL = locateDataH(vote, node->left);
		stringR = locateDataH(vote, node->right);
		return (stringL + stringR);
	}
}

string pMT::locateHash(string mhash)
/**
* @brief Function takes a hash and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root.
* @param mhash, the hash to search for
* @return sequence of L's and R's comprising the movement to the hash node, ; else return a dot '.'
*/
{
	locateHashH(mhash, root);
}

string pMT::locateHashH(string vote, treeNode *leaf)
{
	string seq;
	// If the node is null, the tree contains no data
	if (leaf == NULL)
		return "Empty tree";
	// If the hash of the data in the root matches, there is no sequence
	if (vote == hashS(root->data))
		return "Data in root";
	// If the hashed data in the subtree to the left of the node matches, add an L and recurse
	if (hashS(root->left->data) == vote)
	{
		seq += "L";
		locateHashH(vote, leaf->left);
	}
	// If the hashed data in the subtree to the right of the node matches, add an R and recurse
	if (hashS(root->right->data) == vote)
	{
		seq += "R";
		locateHashH(vote, leaf->right);
	}
	return seq;
}

string pMT::hash_1(string key)
/**
* @brief A function that takes in a key and returns a hash of that key using some custom function
* @param key, a string
* @return a hash of the key
*/
{
	unsigned int hash = 0;

	for (std::size_t i = 0; i < key.length(); i++)
	{
		hash = (hash * i) + key[i];
	}
	//itoa (i,hash,16);
	//hash = std::hex << hash;
	return std::to_string(hash);
}

string pMT::hash_2(string key)
/**
* @brief A function that takes in a key and returns a hash of that key using some custom function
* @param key, a string
* @return a hash of the key
*/
{
	unsigned int hash = 0b0000000000000001;
	unsigned int thing = 0b0001010010100000;

	for (std::size_t i = 0; i < key.length(); i++)
	{
		hash = (hash << key[i]) ^ thing;
	}
	return std::to_string(hash);
}

string pMT::hash_3(string key)
/**
* @brief A function that takes in a key and returns a hash of that key using some custom function
* @param key, a string
* @return a hash of the key
*/
{
	unsigned int hash = 1234;

	for (int i = 0; i < key.length(); i++)
	{
		hash = ((hash << 5) + hash) + key[i];
	}
	return std::to_string(hash);
}

bool operator ==(const pMT& lhs, const pMT& rhs)
/**
* @brief Comparison between two merkle trees
* @param lhs, the left hand side of the equality statment
* @param rhs, the right hand side of the equality statement
* @return true if equal, false otherwise
*/
{
	// If root node hashes match, the trees are equal
	if (lhs.root->data == rhs.root->data)
		return true;
	else
		return false;
}

bool operator !=(const pMT& lhs, const pMT& rhs)
/**
* @brief Comparison between two merkle trees
* @param lhs, the left hand side of the equality statment
* @param rhs, the right hand side of the equality statement
* @return true if not equal, false otherwise
*/
{
	// If root node hashes don't match, the trees are not equal
	if (lhs.root->data != rhs.root->data)
		return true;
	else
		return false;
}

std::ostream& operator <<(std::ostream& out, const pMT& p)
/**
* @brief Print out a tree
* @param out
* @param p
* @return a tree to the screen
*/
{
}


pMT operator ^(const pMT& lhs, const pMT& rhs)
/**
* @brief Where do two trees differ
* @param lhs
* @param rhs
* @return a tree comprised of the right hand side tree nodes that are different from the left
*/
{
}
