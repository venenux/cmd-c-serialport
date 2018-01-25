#
#
# Author: Teunis van Beelen
#
# email: teuniz@gmail.com
#
#

CC = gcc
CFLAGS = -Wall -Wextra -Wshadow -Wformat-nonliteral -Wformat-security -Wtype-limits -o2

rsobjects = rs232.o

all: test_rx test_tx

test_rx : $(rsobjects) demo_rx.o
	$(CC) $(rsobjects) demo_rx.o -o test_rx

test_tx : $(rsobjects) demo_tx.o
	$(CC) $(rsobjects) demo_tx.o -o test_tx

demo_rx.o : demo_rx.c rs232.h
	$(CC) $(CFLAGS) -c demo_rx.c -o demo_rx.o

demo_tx.o : demo_tx.c rs232.h
	$(CC) $(CFLAGS) -c demo_tx.c -o demo_tx.o

rs232.o : rs232.h rs232.c
	$(CC) $(CFLAGS) -c rs232.c -o rs232.o

clean :
	$(RM) test_rx test_tx $(rsobjects) demo_rx.o demo_tx.o rs232.o

# using the lib as static linking

dual_rt : $(rsobjects) dual_rt.o
	$(CC) $(rsobjects) dual_rt.o -o dual_rt

dual_rt.o : dual_rt.c rs232.h
	$(CC) $(CFLAGS) -c dual_rt.c -o dual_rt.o

#
#
#
#


