
#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H


#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class HuffmanNode
{
private:
	int weight;
	int value;
	HuffmanNode* leftChild;
	HuffmanNode* rightChild;
	
public:
	HuffmanNode(int setWeight,int setValue);

	HuffmanNode(HuffmanNode* left, HuffmanNode* right);

	int Value();
	int Weight();

	HuffmanNode* left();
	HuffmanNode* right();

	void traverseTree(HuffmanNode* node, string path, vector<string>& encodings);

};

#endif