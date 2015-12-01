
OBJECTS = main.o readfile.o
HEADERS = readfile.h

all: main

run: main
	./main

%.o: %.c
	gcc -c $^ -o $@

main: $(OBJECTS) $(HEADERS)
	gcc $^ -o main
