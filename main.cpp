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
const float speed = 60.f;
std::vector<std::vector<int>> changed{};

void update(grid& cells, int i);

int main(){
    srand(std::time(nullptr));
    grid cells{};
    bool resized = true;
    
    for(int i = 0; i < height/side; i++){
        std::vector<Cell> row{};
        cells.push_back(row); 
        for(int k = 0; k < width/side; k++){
            Cell cell{k, i, side, side};
            cells[i].push_back(cell);
        }
    }
    
    sf::RenderWindow window(sf::VideoMode(width,height), "SFML Project");
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::Resized)
                    resized = true;
        }
        
        update(cells, 100);
        while(changed.size() > 0){
            window.draw((cells[changed[0][0]][changed[0][1]]));
            changed.erase(changed.begin(), changed.begin()+1);
        }
        window.display();
        if(resized){
            for(int i = 0; i < cells.size(); i++){
                for(int k = 0; k < cells[i].size(); k++){
                    window.draw(cells[i][k]);
                }
            }
        }
        resized = false;
    }
    return 0;
}

void update(grid& cells, int i){
    for(i; i > 0; i--){
        int i = rand()%cells.size();
        int k = rand()%cells[i].size();
        std::vector<int> temp{i,k};
        changed.push_back(temp);
        cells[i][k].setColor(rand()%255, rand()%255, rand()%255);
    }
}
