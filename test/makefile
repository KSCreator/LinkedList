CC := gcc
CFLAGS := -Wall -o3 -std=c11
TARGET = main
OBJECTS := main.o SinglyLinkedList.o DoublyLinkedList.o

# if no changes made it will just run ./main
all: ./main
	./main

# ./main depends on OBJECTS
./main: $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)
# main.c may include these header files
main.o: main.c ../include/*.h
	$(CC) $(CFLAGS) -c main.c -o main.o
SinglyLinkedList.o: ../src/SinglyLinkedList.c ../include/SinglyLinkedList.h
	$(CC) $(CFLAGS) -c ../src/SinglyLinkedList.c -o SinglyLinkedList.o
DoublyLinkedList.o: ../src/DoublyLinkedList.c ../include/DoublyLinkedList.h
	$(CC) $(CFLAGS) -c ../src/DoublyLinkedList.c -o DoublyLinkedList.o
clean:
	rm $(TARGET)
	rm *.o
