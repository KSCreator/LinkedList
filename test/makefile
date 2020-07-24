CC := gcc
CFLAGS := -Wall -o3 -std=c11
TARGET = main
OBJECTS := main.o SinglyLinkedList.o DoublyLinkedList.o

COLOR_RED := \033[0;31m
COLOR_GREEN := \033[0;32m
COLOR_NONE := \033[0m

all: ./main
	@echo "${COLOR_RED}Executing Application${COLOR_NONE}"
	./main


./main: $(OBJECTS)
	@echo "${COLOR_RED}Linking object files${COLOR_GREEN}"
	$(CC) -o $(TARGET) $(OBJECTS)


main.o: main.c ../include/*.h
	@echo "${COLOR_RED}Compiling main.c${COLOR_GREEN}"
	$(CC) $(CFLAGS) -c main.c -o main.o


SinglyLinkedList.o: ../src/SinglyLinkedList.c ../include/SinglyLinkedList.h
	@echo "${COLOR_RED}Compiling SinglyLinkedList.c${COLOR_GREEN}"
	$(CC) $(CFLAGS) -c ../src/SinglyLinkedList.c -o SinglyLinkedList.o

DoublyLinkedList.o: ../src/DoublyLinkedList.c ../include/DoublyLinkedList.h
	@echo "${COLOR_RED}Compiling DoublyLinkedList.c${COLOR_GREEN}"
	$(CC) $(CFLAGS) -c ../src/DoublyLinkedList.c -o DoublyLinkedList.o

clean:
	@echo "${COLOR_RED}cleaning the project${COLOR_GREEN}"
	rm $(TARGET)
	rm *.o
	@echo "${COLOR_NONE}"
