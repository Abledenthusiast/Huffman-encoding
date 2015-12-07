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
   int charCount;
   vector<string> encodings (257);
   /*
   *  count the number of characters in a text file
   *  return an array indexed by ascii value with their frequency
   */
   vector<int> charFreq(string fileName)
   {
      ifstream infile;
      vector<int> count (257);
      infile.open(fileName.c_str());
      /** 
       * while peeking ahead does not reveal end of file
       * take each character and increment the frequency of that character 
       **/
      while(infile.peek() && !infile.eof())
      {
         char ch = infile.get();
         count[ch] = count[ch]+1;    
      }
      // set eof frequency = 1 
      count[PSEUDOEOF] = 1;
      /*
      *  find the number of unique charcters within the file
      */
      int numOfAscii = 0;
      // check every char frequency, except psuedoeof (it's 1)
      for(int i = 0; i < 256; i++)
       {
         if(count[i]!=0)
         {
            numOfAscii = numOfAscii + 1;
            charCount = numOfAscii;
         }
       }
      // return the vector sorted by characters with their frequencies
      return count;
   }


  /*
  * writeFile writes the encoding out to a new compressed file
  *  pass in a fileName to open & a name for a file to output to
  */
  void writeFile(string fileName, string outFile, vector<int> count)
   {
      //------- Read each character again --------         
         ifstream infile;
         obstream output(outFile);

        
         // write the number of characters
        
         output.writebits(32,charCount+1);
         // write the table of unique characters and their frequency
        for(int i = 0; i < 256; i++)
        {
          if(count[i]>0)
          {
            output.writebits(8,i);
            output.writebits(32,count[i]);
          }
        }

         infile.open(fileName.c_str());
        // output.writebits(8, charCount);
         /** while peeking ahead does not reveal end of file **/
         while(infile.peek() && !infile.eof())
         {
            // get the encoding value for each character and add to the final output
            char ch = infile.get();
            if(encodings[ch]!="")
            {              
              for (int i = 0; i < encodings[ch].size(); ++i)
              {
                int bitVal = int(encodings[ch][i]-'0');
                output.writebits(1,bitVal);
              }
            }                      
         }
         // write out PSUEDOEOF path
      for (int i = 0; i < encodings[PSEUDOEOF].size(); ++i)
              {
                int bitVal = int(encodings[PSEUDOEOF][i]-'0');
                output.writebits(1,bitVal);
              }   
      // close the output file     
      output.close();
   }

   HeapNode buildTree(priority_queue<HeapNode> leafNodes)
   { 

     priority_queue<HeapNode> myHeap = leafNodes;
     while (myHeap.size()>1)
       {
         HeapNode firstNode = myHeap.top();
         myHeap.pop();
         HeapNode secondNode = myHeap.top();
         myHeap.pop();

         cout << "sub tree left weight: "<< firstNode.value()->Weight() << endl;
         cout << "sub tree right weight: "<< secondNode.value()->Weight() << endl;

         cout << "sub tree left value: "<< firstNode.value()->Value() << endl;
         cout << "sub tree right value: "<< secondNode.value()->Value() << endl;
         
         HeapNode parent;
         parent.buildNode(firstNode.value(), secondNode.value());

         
         cout << "parent weight: " << parent.value()->Weight() << endl;
         cout << "" << endl;

         myHeap.push(parent);
       } 
      return myHeap.top();
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
      // only insert ascii codes that actually appear
      for(int i = 0; i < 256; i++)
       {
         if(freq[i]!=0)
         {
            insertVal.buildLeaf(freq[i], i);
            myHeap.push(insertVal);
         }
       }
      insertVal.buildLeaf(1, PSEUDOEOF);
      myHeap.push(insertVal);

       //build the huffman tree with the leaf nodes contained in the heap
       HeapNode HuffmanTree = buildTree(myHeap);
      
       // create encodings for each character 
       
      HuffmanTree.value()->traverseTree(HuffmanTree.value(), "", encodings);
     

      /** print to file the bits as a string **/
      writeFile(argv[1], "compressed.txt", freq);

      return 0;
   }
