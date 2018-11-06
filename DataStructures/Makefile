
default: linkedlist binarytree Que Stack 
	CFLAGS= \
  -ggdb \
  -std=c89 \
  -pedantic \
  -pedantic-errors \
  -Werror \
  -Wextra \
  -Wmissing-prototypes \
  -Wall \
  -Wold-style-definition \
  -Wdeclaration-after-statement \
  -Wundef \
  -Wpointer-arith \
  -Wcast-qual \
  -Wcast-align \
  -Wfloat-equal \
  -Wno-missing-braces \
  -Wincompatible-pointer-types
linkedlist:
	gcc Linkedmain.c menulinkedlists.c $(CFLAGS) -o linkedlist

binarytree:
	gcc binarytree.c Binarymenu.c $(CFLAGS) -o binarytree
	
fifolifostack: 
	gcc fifolifostack.c fifolifostackmenu.c $(CFLAGS) -o stackque


