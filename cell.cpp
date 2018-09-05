#include "cell.h"
#include <sstream>

Cell::Cell(int x, int y, int width, int height, sf::Color color): x{x}, y{y}, width{width}, height{height}, color{color} {
    changed = true;
    sf::Vector2<float> size{width,height};
    
    sf::RectangleShape tempRect{size};
    rect = tempRect;
    rect.setPosition(x*width, y*height);
    rect.setFillColor(color);
}

void Cell::draw(sf::RenderWindow& window){
    window.draw(rect);
}

std::string Cell::toString() const{
    std::stringstream buffer{};
    buffer << x << " " << y << " " << width << " " << height << " (" << (int) color.r << "," << (int) color.g << "," << (int) color.b << ")";
    return buffer.str();
}

sf::RectangleShape& Cell::getRect(){
    changed = false;
    return rect;
}

std::ostream& operator<<(std::ostream& os, const Cell& cell){
    return os << cell.toString();
}

void Cell::setColor(int r, int g, int b){
    changed = true;
    color.r = r;
    color.g = g;
    color.b = b;
    rect.setFillColor(color);
}
