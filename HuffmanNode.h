#include <string>
#include <iostream>
#include <vector>
#include <map>


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

	void traverseTree(HuffmanNode* node, string path, vector<string>& encodings)
	{
		//cout << encoding << endl;
		if(node->left()== NULL && node->right() == NULL)
		{
			char ch = (char)node->value;
			//the following is for formatting's sake
			if(node->value==10)
			{
				cout << "leaf ascii value: " << node->value << "(/n) Path: ";
			}
			else{
				cout << "leaf ascii value: " << node->value << '('<<ch<<')' << " Path: ";
			}			 
			cout<< path << endl;

			encodings[node->Value()] = path;
		}
		if(node->left()!= NULL)
		{
			traverseTree(node->leftChild, path+'0', encodings);	
		}
		if(node->right() != NULL)
		{	
			traverseTree(node->rightChild, path+'1', encodings);			
		}
		return;		
	}

};
#endif