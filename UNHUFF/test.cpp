   #include <iostream>
   #include <string>
   #include <vector>
   #include <map>
   #include <stdlib.h>
   #include "bitops.h"
   #include "HeapNode.h"
   #include "HuffmanNode.h"


/*
* Author: Aaron Pitman
*
* Program takes a text file, reads each character and creates a huffman tree for compression
* 
* version 11/18/2015
*/

   using namespace std;

   int const PSEUDOEOF = 256;

   string result;
   /*
   * buildTree takes a heap of leafNodes and creates returns huffman tree
   * the huffMan tree is contained within a heapNode
   */
   HeapNode buildTree(priority_queue<HeapNode> leafNodes)
   { 

     priority_queue<HeapNode> myHeap = leafNodes;
     while (myHeap.size()>1)
       {
         HeapNode firstNode = myHeap.top();
         myHeap.pop();
         HeapNode secondNode = myHeap.top();
         myHeap.pop();
         /*
         cout << "sub tree left weight: "<< firstNode.value()->Weight() << endl;
         cout << "sub tree right weight: "<< secondNode.value()->Weight() << endl;

         cout << "sub tree left value: "<< firstNode.value()->Value() << endl;
         cout << "sub tree right value: "<< secondNode.value()->Value() << endl;
         */
         HeapNode parent;
         parent.buildNode(firstNode.value(), secondNode.value());

         
        // cout << "parent weight: " << parent.value()->Weight() << endl;
         //cout << "" << endl;

         myHeap.push(parent);
       } 
      return myHeap.top();
   }
   /*
    this is a test area!
   */

  //------------------------------------------------------

   /*
   *  count the number of characters in a text file
   *  
   */
   void readIn(string fileName)
   {
      ifstream infile;
      
      infile.open(fileName.c_str());
      // init 
      priority_queue<HeapNode> myHeap;
      HeapNode insertVal; 
       char ch;      
       int frequency;
       // set up the loop for n number of characters
      int loopTime = infile.get();
      // convert char to int
      loopTime = loopTime - '0';

       // set up leaf values for huffman tree
      while(loopTime>0)
      {
        ch = infile.get();
        // how often my character appears
        infile >> frequency; 
        // space after (char,freq) pair
        infile.get(); 
        // create leaf with the character and it's frequency as the values
        insertVal.buildLeaf(frequency, ch);
        myHeap.push(insertVal);
        // 1 more character down, move on to the next (if any are left)
        loopTime--;
      }
      // insert leaf of PSEUDOEOF
      insertVal.buildLeaf(1, PSEUDOEOF);
      myHeap.push(insertVal);
      // create the huffman tree
      HeapNode HuffmanTree = buildTree(myHeap);
      //----------------------------------------

      // we're now to the compressed bits
      
      HuffmanNode* currentNode;
      string output = "";
      // init currentNode to refer to the root
      currentNode = HuffmanTree.value();
      while(infile.peek() && !infile.eof())
      {
        ch = infile.get();    
        // left on 0, right on 1
        if(ch=='0')
        {
          cout << "I went left" << endl;
          currentNode = currentNode->left();
          if(currentNode->Value()!=-1)
          {
            cout <<  "I'm an ascii value!" << endl;
            char temp = currentNode->Value();
            cout << temp << endl;
            output.push_back(temp);
            // go back to the top
            currentNode = HuffmanTree.value();
          }
        }
        else
        {
          cout << "I went right" << endl;
          currentNode = currentNode->right();
          if(currentNode->Value()!=-1)
          {
            cout <<  "I'm an ascii value!" << endl;
            
            char temp = currentNode->Value();
            output.push_back(temp);
            // go back to the top
            currentNode = HuffmanTree.value();
          }
        }
      }  
      cout << output << endl;
   }

   int main(int argc, char * argv[])
   {
      string newFile;
      if (argc > 1)
      {
        readIn(argv[1]);
      }
      else
      {
         cerr << "usage: " << argv[0] << " <filename>" << endl;
         exit(1);
      }


      return 0;
   }
