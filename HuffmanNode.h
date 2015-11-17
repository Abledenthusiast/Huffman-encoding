#include <string>
#include <iostream>
#include <vector>


/**
 * @author Aaron Pitman 
 * @version 2015.11.04
 */
 
using namespace std;

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

class HuffmanNode
{
private:
	int weight;
	int value;
	HuffmanNode* leftChild;
	HuffmanNode* rightChild;
	
public:
	HuffmanNode(int setWeight,int setValue)
	{
		weight = setWeight;
		value = setValue;
		leftChild = NULL;
		rightChild = NULL;
	}
	HuffmanNode(HuffmanNode* left, HuffmanNode* right)
	{
		leftChild = left;
		rightChild = right;
		value = -1;
		weight = leftChild->Weight() + rightChild->Weight();
	}
	int Value()
	{
		return value;
	}

	int Weight()
	{
		return weight;
	}

	HuffmanNode* left()
	{
		return leftChild;
	}


	HuffmanNode* right()
	{
		return rightChild;
	}

};
#endif