all: Lab1_PMS

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

Lab1_PMS: PMS.o
	cc -o $@ $^
Lab1_PMS.o: PMS.c addEmployee.h deleteEmployee.h
	cc -c $(CFLAGS) PMS.c
clean:
	rm -f *.o Lab1_PMS
