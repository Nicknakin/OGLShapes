#include "cell.h"
#include <sstream>

Cell::Cell(int x, int y, int width, int height, sf::Color color): x{x}, y{y}, width{width}, height{height}, color{color} {
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
    return rect;
}

std::ostream& operator<<(std::ostream& os, const Cell& cell){
    return os << cell.toString();
}
