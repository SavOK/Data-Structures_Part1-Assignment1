CC = gcc
CCFLAGS = -O2 -pipe -std=c11

SRCDIR= ./src
PROGDIR = ./prog


all: $(PROGDIR) fib fibonacci_huge fibonacci_last_digit gcd lcm

$(PROGDIR):
	mkdir -p $(PROGDIR)

fib:
	$(CC) $(CCFLAGS) $(SRCDIR)/fib.c -o $(PROGDIR)/fib

fibonacci_last_digit:
	$(CC) $(CCFLAGS) $(SRCDIR)/fibonacci_last_digit.c -o $(PROGDIR)/fibonacci_last_digit

gcd:
	$(CC) $(CCFLAGS) $(SRCDIR)/gcd.c -o $(PROGDIR)/gcd

lcm:
	$(CC) $(CCFLAGS) $(SRCDIR)/lcm.c -o $(PROGDIR)/lcm

fibonacci_huge:
	$(CC) $(CCFLAGS) $(SRCDIR)/fibonacci_huge.c -o $(PROGDIR)/fibonacci_huge


