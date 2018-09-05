#include "cell.h"
#include <sstream>

Cell::Cell(int x, int y, int width, int height, sf::Color color): x{x}, y{y}, width{width}, height{height}, color{color}, sf::RectangleShape(sf::Vector2<float>{width, height}) {
    changed = true;
    setPosition(x*width, y*height);
    setFillColor(color);
}

std::string Cell::toString() const{
    std::stringstream buffer{};
    buffer << x << " " << y << " " << width << " " << height << " (" << (int) color.r << "," << (int) color.g << "," << (int) color.b << ")";
    return buffer.str();
}


std::ostream& operator<<(std::ostream& os, const Cell& cell){
    return os << cell.toString();
}

void Cell::setColor(int r, int g, int b){
    changed = true;
    color.r = r;
    color.g = g;
    color.b = b;
    setFillColor(color);
}
