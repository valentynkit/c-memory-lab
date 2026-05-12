CC = gcc
CFLAGS = -Wall -Wextra -g -O0

SRCS = $(wildcard *.c)
PROGRAMS = $(SRCS:.c=)

all: $(PROGRAMS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS)

.PHONY: all clean
