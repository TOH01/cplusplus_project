#include "cell.hpp"

Cell::Cell() : currentType(Type::Empty) {} 

void Cell::setType(Type newType) {
    currentType = newType;  
}

Cell::Type Cell::getType() {
    return currentType; 
}

sf::Color Cell::getColor(Position position){
    switch (currentType)
    {
    case Type::Border:
        return BORDER_COLOR;
    case Type::SnakeBody:
        return SNAKE_BODY_COLOR;
    case Type::SnakeHead:
        return SNAKE_HEAD_COLOR;
    case Type::Food:
        return FOOD_COLOR;
    case Type::Empty:
        // this will make chessboard pattern
        if((position.x + position.y) % 2 == 0){
            return EMPTY_COLOR_1;
        }
        else{
            return EMPTY_COLOR_2;
        }   
    default:
        return sf::Color::Black; // fallback color
    }
}