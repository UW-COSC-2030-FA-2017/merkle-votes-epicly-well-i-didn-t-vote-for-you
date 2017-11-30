#pragma once

#include <string>
using namespace std;

class bTREE
{
	struct treeNode {
		string data;
		int time;
		treeNode *left;
		treeNode *right;
		bool leaf;
	};

private:
	//some data structure to hold your treeNodes together ...
	//DATASTUCTURE treeNodes tree;
	//any helper private variables you need

	int numberOfNodesH(treeNode *leaf);
	treeNode *root;

public:
	bTREE();
	~bTREE();

	int dataInserted();
	
	int numberOfNodes();

	int insert(treeNode *node, string dat, int tim);

	int find(treeNode *node, string dat);

	string locate(treeNode *node, string dat);

	void displayLeft(std::ostream& outfile, treeNode *subtree, string prefix);

	void displayRight(std::ostream& outfile, treeNode *subtree, string prefix);

	void display(std::ostream& outfile);

	friend bool operator==(const bTREE& lhs, const bTREE& rhs);
	friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

	friend std::ostream& operator<<(std::ostream& out, const bTREE& p);

};
