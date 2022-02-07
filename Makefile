CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -ggdb `pkg-config --cflags sdl2`
LIBS = `pkg-config --libs sdl2` -lm

te: main.c
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

clean:
	rm -vf te

