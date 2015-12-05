CC	= g++
INCLUDE	= -I/usr/local/include
#Windows users comment-out the above line and uncomment the line below
#INCLUDE	= -I/MinGW/msys/1.0/local/include

LIBS = -L/usr/local/lib
#Windows users comment out the above line and uncomment the line below
#LIBS = -L/MinGW/msys/1.0/local/lib

CFLAGS  = -g

Huff: test.o  
	$(CC) -o Huff $(INCLUDE) $(LIBS) $(CFLAGS) test.o -lcurl

.cpp.o:	
	$(CC) $(INCLUDE) $(CFLAGS) $(LIBS) -c $< -o $@

