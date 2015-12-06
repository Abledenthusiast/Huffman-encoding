#include <iostream>
#include <stdlib.h>
#include "bitops.h"
using namespace std;
// demonstrates some use of bitstream operations

void echo(ibstream & input)
{
   string name;
   cout << "enter name of output file: ";
   cin >> name;
   obstream output;
   int inbits;

   output.open(name);

   input.rewind();
   while (input.readbits(1, inbits)) 
     /* reads 1 bit, stores it as the rightmost value of inbits, so
   inbits is now either 1 or 0 */
   {
     output.writebits(1, inbits); // writes a single bit
   }

   output.close();
}


int main(int argc, char * argv[])
{
   ibstream infile;
    
   if (argc > 1)
   {
      infile.open(argv[1]);
   }
   else
   {
      cerr << "usage: " << argv[0] << " <filename>" << endl;
      exit(1);
   }

   echo(infile);
   cout << "one more time around" << endl;
   echo(infile);

   return 0;
}