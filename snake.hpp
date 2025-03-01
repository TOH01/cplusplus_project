#pragma once

#include "grid.hpp"
#include "constants.hpp"
#include <deque>

class Snake {
    public:
        enum class Direction { Up, Down, Left, Right};
        Snake(Grid & grid);
        void grow();
        void setDirection(Direction newDirection);
        void move();
    private:
        Grid& grid;
        
        std::deque<Position> body;

        Direction currentDirection;

        bool hasEaten;
        bool gameOver(Position newHead);
};