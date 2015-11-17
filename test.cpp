#include <iostream>
#include <vector>
#include <stdlib.h>
#include "bitops.h"
#include "HeapNode.h"
#include "HuffmanNode.h"

using namespace std;

int const PSEUDOEOF = 256;
/*
*  count the number of characters in a text file
*  return an array indexed by ascii value with their frequency
*/
vector<int> charFreq(string fileName)
{
   ifstream infile;
   vector<int> count (257);
   infile.open(fileName.c_str());
   /** while peeking ahead does not reveal end of file **/
   while(infile.peek() && !infile.eof())
   {
      char ch = infile.get();
      count[ch] = count[ch]+1;     
   }
   count[PSEUDOEOF] = 1;
  
   return count;
}

int main(int argc, char * argv[])
{
   vector<int> freq;

   if (argc > 1)
   {
      freq = charFreq(argv[1]);
   }
   else
   {
      cerr << "usage: " << argv[0] << " <filename>" << endl;
      exit(1);
   }
   

   priority_queue<HeapNode> myHeap;
   HeapNode insertVal;

   

   for(int i = 0; i < 256; i++)
    {
      if(freq[i]!=0)
      {
         cout << freq[i] << " i: " << i << endl;
         insertVal.buildLeaf(freq[i], i);
         myHeap.push(insertVal);
      }

    }
    cout << "" << endl;
  while (myHeap.size()>1)
    {
      HeapNode firstNode= myHeap.top();
      myHeap.pop();
      HeapNode secondNode = myHeap.top();
      myHeap.pop();

      cout << firstNode.value()->Weight() << endl;
      cout << secondNode.value()->Weight() << endl;

      
      HeapNode parent;
      parent.buildNode(firstNode.value(), secondNode.value());

      
      cout << "parent weight: " << parent.value()->Weight() << endl;
      cout << "" << endl;

      myHeap.push(parent);
    } 
    return 0;
}