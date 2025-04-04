CC = gcc

CFLAGS = -std=c11

SRCS = src/main.c src/metrics.c src/parser.c

OBJS = $(SRCS:.c=.o)

EXEC = pizzeriac

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean