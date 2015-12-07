CC	= g++
INCLUDE	= -I/usr/local/include
#Windows users comment-out the above line and uncomment the line below
#INCLUDE	= -I/MinGW/msys/1.0/local/include

LIBS = -L/usr/local/lib
#Windows users comment out the above line and uncomment the line below
#LIBS = -L/MinGW/msys/1.0/local/lib

CFLAGS  = -g

unHuff: unhuff.o bitops.o HeapNode.o HuffmanNode.o 
	$(CC) -o unHuff $(INCLUDE) $(LIBS) $(CFLAGS) unhuff.o bitops.o HeapNode.o HuffmanNode.o -lcurl

.cpp.o:	
	$(CC) $(INCLUDE) $(CFLAGS) $(LIBS) -c $< -o $@

