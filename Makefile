#
# Makefile
# Chris Kyle
# ckyle@ucsc.edu
#
# Description:
#    A Makefile for the first programming assignment
#    of cs104a.
#
GPP   = g++ -g -O0 -Wall -Wextra -std=gnu++11
GRIND = valgrind --leak-check=full --show-reachable=yes


all : ss

ss : secretSanta.o
	${GPP} secretSanta.o -o secretSanta

%.o : %.cpp
	${GPP} -c $<

ci :
	git add secretSanta

clean :
	-rm *.o
	-rm secretSanta
