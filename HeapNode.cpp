#include <string>
#include <iostream>
#include <vector>
#include <queue> 
#include "HuffmanNode.h"
#include "HeapNode.h"

/**
 * @author Aaron Pitman 
 * @version 2015.11.04
 */
 
using namespace std;

	HeapNode::HeapNode()//int setWeight, setValue)
	{
	}

 	bool HeapNode::operator<(const HeapNode &rightHandArgument) const
  {
    int thisWeight = pointerToHuff->Weight();
    int OtherWeight = rightHandArgument.value()->Weight();
    return (thisWeight > thisWeight);
  }

  HuffmanNode* HeapNode::value() const
  {
  	return pointerToHuff;
  }

  void HeapNode::buildLeaf(int weight, int value)
  {
  	pointerToHuff = new HuffmanNode(weight, value);
  }

  void HeapNode::buildNode(HuffmanNode* left, HuffmanNode* right)
  {
  	pointerToHuff = new HuffmanNode(left, right);
  }