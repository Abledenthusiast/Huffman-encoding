   #include <iostream>
   #include <string>
   #include <vector>
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
   *  function takes in a fileName to open and read in
   *  decompresses the huffman encoded file
   */
   void readIn(string fileName)
   {
      ibstream infile(fileName);
      
      // init 
      priority_queue<HeapNode> myHeap;
      HeapNode insertVal; 
      int inbits;      
      int frequency;
      int ch;
      vector<int> count;
       // set up the loop for n number of characters
      int loopTime;
      infile.readbits(32,inbits);
      // looptime = int number inbits converts to
      loopTime = inbits;
       // set up leaf values for huffman tree
      while(loopTime>1)
      {
        // get the unique characters        
        infile.readbits(8,ch);
        
     
        // frequency of that character
        infile.readbits(32,frequency);
   

        insertVal.buildLeaf(frequency, ch);
        myHeap.push(insertVal);
        
        // 1 more character down, move on to the next (if any are left)
        loopTime--;
      }
       //insert leaf of PSEUDOEOF
      insertVal.buildLeaf(1,PSEUDOEOF);
      myHeap.push(insertVal);
      // create the huffman tree
      HeapNode HuffmanTree = buildTree(myHeap);
      //----------------------------------------

      // we're now to the compressed bits
      
      HuffmanNode* currentNode;
      string output = "";
      // init currentNode to refer to the root
      currentNode = HuffmanTree.value();
      bool traversing = true;
      while (infile.readbits(1,inbits)&&traversing) 
      {   
        // left on 0, right on 1
        cout << "bit read: " << inbits << endl;
        if(inbits==0)
        {
          // set the value of currentNode = currentNode's left child
          currentNode = currentNode->left();
          // check if the leaf is signifying the end of the file.
          if(currentNode->Value()==PSEUDOEOF)
          {
            traversing = false;
          }

          if(currentNode->Value()!=-1)
          {
            //cout <<  "I'm an ascii value!" << endl;
            char temp = currentNode->Value();
            cout << "char found at leaf: " << temp << endl;
            output.push_back(temp);
            // go back to the top
            currentNode = HuffmanTree.value();
          }
         }
        else
        {
          // set the value of currentNode = currentNode's right child
          currentNode = currentNode->right();
          // check if the leaf is signifying the end of the file.
          if(currentNode->Value()==PSEUDOEOF)
          {
            traversing = false;
          }
          if(currentNode->Value()!=-1)
          {
            char temp = currentNode->Value();
            output.push_back(temp);
            cout << "char found at leaf: " << temp << endl;
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
