
#ifndef HEAPNODE_H
#define HEAPNODE_H

#include <string>
#include <iostream>
#include <vector>
#include <queue> 
#include "HuffmanNode.h"

using namespace std;

class HeapNode
{
private:
	HuffmanNode* pointerToHuff;
	
public:
	HeapNode();

 	bool operator<(const HeapNode &rightHandArgument) const;

  HuffmanNode* value() const;

  void buildLeaf(int weight, int value);

  void buildNode(HuffmanNode* left, HuffmanNode* right);


};

#endif