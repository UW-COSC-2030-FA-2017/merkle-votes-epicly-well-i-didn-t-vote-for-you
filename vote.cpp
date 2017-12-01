#include <stdio.h>
#include<iostream>
#include<fstream>
#include "pMT.h"
#include "bTREE.h"
using namespace std;

int main(int argc, char **argv)
{
	pMT merkleTest1 = pMT(1);
	pMT merkleTest2 = pMT(1);
	ifstream readFile;
	string vote;
	int timestamp;
	
	readFile.open("fdlkjgas");
	
	while (readFile.fail())
	{
		cerr << "Error opening file." << endl;
		exit(1);
	}

	while (readFile.good())
	{
		readFile >> vote;
		readFile >> timestamp;
		merkleTest1.insert(vote,timestamp);
	}

	readFile.close();


	readFile.open("dflkjdfg");

	while (readFile.fail())
	{
		cerr << "Error opening file." << endl;
		exit(1);
	}

	while (readFile.good())
	{
		readFile >> vote;
		readFile >> timestamp;
		merkleTest2.insert(vote, timestamp);
	}

	readFile.close();

	if (merkleTest1 == merkleTest2)
		printf("Validated");
	else
		// Print subtrees that differs

	return 0;
}
