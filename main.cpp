#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "cell.h"

#define grid std::vector<std::vector<Cell>>

int width = 800, height = 800;
int side = 1;
int x = 0, y = 0, xI = 1, yI = 1, xMax = width/side, yMax = height/side;

void sleepcp(int);
void update(grid& cells);

int main(){
        srand(std::time(nullptr));

    grid cells{};
    for(int i = 0; i < height/side; i++){
        std::vector<Cell> row{};
        cells.push_back(row); 
        for(int k = 0; k < width/side; k++){
            Cell cell{k, i, side, side};
            cells[i].push_back(cell);
        }
    }
    
    sf::RenderWindow window(sf::VideoMode(width,height), "SFML Project");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        update(cells);
        for(int i = 0; i < cells.size(); i++){
            for(int k = 0; k < cells[i].size(); k++){
                if(cells[i][k].changed)
                    window.draw((cells[i][k].getRect()));
            }
        }
        window.display();
    }
    return 0;
}

void sleepcp(int milliseconds) // Cross-platform sleep function
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end)
    {
    }
}

void update(grid& cells){
    int i = rand()%cells.size();
    int k = rand()%cells[i].size();
    cells[i][k].setColor(rand()%255, rand()%255, rand()%255);
}
