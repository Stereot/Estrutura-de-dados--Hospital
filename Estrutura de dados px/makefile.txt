CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJECTS = hospital.o main.o
TARGET = hospital

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

hospital.o: hospital.c hospital.h
	$(CC) $(CFLAGS) -c hospital.c

main.o: main.c hospital.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJECTS) $(TARGET)
