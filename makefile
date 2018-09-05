CXX = g++
oglflags = -lsfml-graphics -lsfml-window -lsfml-system

default: main.o cell.o
	$(CXX) -o run main.o cell.o $(oglflags)

debug: main.o cell.o
	$(CXX) -g -Wall -o run main.cpp cell.cpp $(oglflags)

main: main.cpp
	$(CXX) -c main.cpp $(oglflags)

cell: cell.cpp cell.h
	$(CXX) -c cell.cpp $(oglflags)

clean:
	rm -rf *.o run