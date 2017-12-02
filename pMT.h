#pragma once

#include "bTREE.h"
#include <string>
using namespace std;
class pMT
{
	struct treeNode {
		string data;
		int time;
		treeNode *left;
		treeNode *right;
	};
private:
	int selectedHash;
	//bTREE myMerkle;
	
	treeNode *root;
	string hash_1(string);
	string hash_2(string);
	string hash_3(string);

public:
	pMT(int);
	~pMT();

	string hashS(string data);

	int insert(string, int);

	int find(string vote, int time, int hashSelect);
	int findHash(string);
	int findHashH(string mhash, treeNode *root);

	string locateData(string);
	string locateDataH(string vote, treeNode *root);
	string locateHash(string);
	string locateHashH(string vote, treeNode *root);

	friend bool operator==(const pMT& lhs, const pMT& rhs);

	friend bool operator!=(const pMT& lhs, const pMT& rhs);

	friend pMT operator^(const pMT& lhs, const pMT& rhs);
	friend std::ostream& operator<<(std::ostream& out, const pMT& p);

};
