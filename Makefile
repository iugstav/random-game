CFLAGS = -Wall -Wextra
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

FILE = circle.c

main: $(FILE)
	gcc $(CFLAGS) -o main $(FILE) $(LIBS)
