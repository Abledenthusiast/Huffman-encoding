#include <string>
#include <iostream>
#include <vector>
#include <queue> 
#include "HuffmanNode.h"

/**
 * @author Aaron Pitman 
 * @version 2015.11.04
 */
 
using namespace std;

#ifndef HEAPNODE_H
#define HEAPNODE_H

class HeapNode
{
private:
	HuffmanNode* pointerToHuff;
	
public:
	HeapNode()//int setWeight, setValue)
	{
	}

 	bool operator<(const HeapNode &rightHandArgument) const
  {
    int myWeight = pointerToHuff->Weight();
    int hisWeight = rightHandArgument.value()->Weight(); // stay away from ladies being called fat...
    											// use hisWeight and live a happy life =)
    return (myWeight > hisWeight);
  }

  HuffmanNode* value() const
  {
  	return pointerToHuff;
  }

  void buildLeaf(int weight, int value)
  {
  	pointerToHuff = new HuffmanNode(weight, value);
  }

  void buildNode(HuffmanNode* left, HuffmanNode* right)
  {
  	pointerToHuff = new HuffmanNode(left, right);
  }


};
#endif