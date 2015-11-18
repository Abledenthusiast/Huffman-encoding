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

	void traverseTree(HuffmanNode* node, string encoding)
	{
		//cout << encoding << endl;
		if(node->left()== NULL && node->right() == NULL)
		{
			cout << "leaf ascii value: " << node->Value() << " Path: " << encoding << endl;
			
			return;
			//return encoding;
		}
		if(node->left()!= NULL)
		{
			
			traverseTree(node->leftChild, encoding+'0');
			
		}
		if(node->right() != NULL)
		{
		
			traverseTree(node->rightChild, encoding+'1');
			
		}
				
	}

};
#endif