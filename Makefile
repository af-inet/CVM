
VM_OBJECTS = vm/main.o vm/readfile.o
VM_HEADERS = vm/readfile.h

all: cvm

run: cvm
	./cvm

%.o: %.c
	gcc -c $^ -o $@

cvm: $(VM_OBJECTS) $(VM_HEADERS)
	gcc $^ -o cvm
