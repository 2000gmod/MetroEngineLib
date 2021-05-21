CC = g++
CFLAGS = -Wall -g -lm `sdl2-config --cflags --libs`
TARGET = graph

.PHONY: compile clean run

default: compile

compile:
	$(CC) -o $(TARGET) $(shell find . -name '*.cpp') $(CFLAGS)

clean:
	rm -f $(TARGET)

run: clean compile
	./$(TARGET)
