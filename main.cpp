#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "cell.h"

int main(){
    int width = 800, height = 800;
    int side = 10;
    
    srand(std::time(nullptr));

    
    
    sf::RenderWindow window(sf::VideoMode(width,height), "SFML Project");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        std::vector<std::vector<Cell>> cells{};
        for(int i = 0; i < height/side; i++){
            std::vector<Cell> row{};
            cells.push_back(row); 
            for(int k = 0; k < width/side; k++){
                Cell cell{i, k, side, side, sf::Color((int) rand()%255, (int) rand()%255, (int) rand()%255)};
                cells[i].push_back(cell);
            }
        }
        window.clear();
        for(int i = 0; i < cells.size(); i++){
            for(int k = 0; k < cells[i].size(); k++){
                window.draw((cells[i][k].getRect()));
                
            }
        }
        window.display();
    }
    return 0;
}
