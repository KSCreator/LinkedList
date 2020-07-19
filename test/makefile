#to make 
CC := gcc
CFLAGS := -Wall -o3 -std=c11
BIN = bin
TARGET = main
OBJECTS := main.o SinglyLinkedList.o DoublyLinkedList.o

all: $(OBJECTS)
	$(CC) -o $(BIN)/$(TARGET) $(OBJECTS)
	./main
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
SinglyLinkedList.o: ../src/SinglyLinkedList.c
	$(CC) $(CFLAGS) -c SinglyLinkedList.c -o SinglyLinkedList.o
DoublyLinkedList.o: ../src/DoublyLinkedList.c
	$(CC) $(CFLAGS) -c DoublyLinkedList.c -o DoublyLinkedList.o
clean:
	rm $(TARGET)
	rm *.o
