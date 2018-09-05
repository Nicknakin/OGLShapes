CXX = g++
oglflags = -lsfml-graphics -lsfml-window -lsfml-system

default: cell.o main.o
	$(CXX) -o shapes.out main.o cell.o $(oglflags)

debug: main.o cell.o
	$(CXX) -g -Wall -o dbgshapes.out main.cpp cell.cpp $(oglflags)

main: main.cpp
	$(CXX) -c main.cpp $(oglflags)

cell: cell.cpp cell.h
	$(CXX) -c cell.cpp $(oglflags)

clean:
	rm -rf *.o *.out
