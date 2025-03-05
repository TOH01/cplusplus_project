#pragma once

#include <SFML/Graphics.hpp>
#include "constants.hpp"

class Cell {
    public:
        enum class Type { Empty, SnakeBody, SnakeHead, Food, Border};
    
        Cell();
        
        void setType(Type newType);
        Type getType();
        sf::Color getColor(Position position);
    private:
        Type currentType;
};