#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "cell.h"

int main(){
    int width = 800, height = 800;
    int side = 10;
    
    srand(100);


    sf::RenderWindow window(sf::VideoMode(width,height), "SFML Project");
    std::vector<std::vector<Cell>> cells{};
    cells.reserve(height/side); 
    for(int i = 0; i < cells.size(); i++){
        std::vector<Cell> row{};
        row.reserve(width/side);
        cells[i] = row; 
        for(int k = 0; k < cells[i].size(); k++){
            Cell cell{i, k, side, side, sf::Color(rand()%255, rand()%255, rand()%255)};
            cells[i][k] = cell;
        }
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for(int i = 0; i < cells.size(); i++){
            for(int k = 0; k < cells[i].size(); k++){
                cells[i][k].draw(window);
                std::cout << cells[i][k].toString();
            }
        }
        window.display();
    }

    return 0;
}
