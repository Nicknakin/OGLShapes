#ifndef cellInc
#define cellInc

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>

class Cell{
    public:
        Cell(int x, int y, int width, int height, sf::Color color = sf::Color(255,255,255));
        void draw(sf::RenderWindow& window);
        std::string toString() const;
        sf::RectangleShape& getRect();
        friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
    private:
        sf::RectangleShape rect;
        sf::Color color;
        int x, y, width, height;
};

#endif
