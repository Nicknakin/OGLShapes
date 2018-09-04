#include "cell.h"

Cell::Cell(int x, int y, int width, int height, sf::Color color): x{x}, y{y}, width{width}, height{height}, color{color} {
    sf::Vector2<float> size{width,height};
    
    sf::RectangleShape tempRect{size};
    rect = tempRect;
    rect.setPosition(x, y);
    rect.setFillColor(color);
}

void Cell::draw(sf::RenderWindow& window){
    window.draw(rect);
}

std::String Cell::toString(){
    std::String str = x + " " + y + " " + width + " " + height + " " + color;
    return str;
}
