CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -ggdb `pkg-config --cflags sdl2`
LIBS = `pkg-config --libs sdl2` -lm

te: main.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -vf te *.o

