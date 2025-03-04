#pragma once

#include "grid.hpp"
#include "constants.hpp"
#include <deque>

class Snake {
    public:
        enum class Direction { Up, Down, Left, Right};
        Snake(Grid & grid);
        void setDirection(Direction newDirection);
        void move();
        bool getGameOverStatus();
        void reset();
        int getScore();
    private:
        Grid& grid;
        
        std::deque<Position> body;

        Direction currentDirection;

        bool gameOver;
        bool hasEaten;
        bool isGameOver(Position newHead);
};