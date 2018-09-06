#include <stdlib.h>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>

#include "cell.h"
#include "grid.h"

int width = 800, height = 800;
int side = 10;
int x = 0, y = 0, xI = 1, yI = 1, xMax = width/side, yMax = height/side;
const float speed = 60.f;

std::vector<std::vector<int>> changed;

void update(Grid& cells, int i);

int main(){
    srand(std::time(nullptr));
    bool resized = true;
    
    Grid cells{width/side, height/side, side};

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
        
        update(cells, 50);
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

void update(Grid& cells, int in){
    for(in; in > 0; in--){
        int i = rand()%cells.size();
        int k = rand()%cells[i].size();
        std::vector<int> temp{i,k};
        changed.push_back(temp);
        cells.setColor(i, k, rand()%255, rand()%255, rand()%255);
    }
}
