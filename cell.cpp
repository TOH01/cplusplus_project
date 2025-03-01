#include "cell.hpp"

Cell::Cell(){
    currentType = Type::Empty;
} 

void Cell::setType(Type newType) {
    currentType = newType;  
}

Cell::Type Cell::getType() {
    return currentType; 
}

sf::Color Cell::getColor(Position position){
    if(currentType == Type::Border){
        return BORDER_COLOR;
    }
    if(currentType == Type::Empty){
        if((position.x + position.y) % 2 == 0){
            return EMPTY_COLOR_1;
        }
        else{
            return EMPTY_COLOR_2;
        }
    }
    if(currentType == Type::SnakeBody){
        return SNAKE_BODY_COLOR;
    }
    if(currentType == Type::SnakeHead){
        return SNAKE_HEAD_COLOR;
    }
    if(currentType == Type::Food){
        return FOOD_COLOR;
    }
    else{
        // fallback color
        return sf::Color::Black;
    }
}