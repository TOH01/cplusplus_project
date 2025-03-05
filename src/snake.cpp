#include "snake.hpp"
#include <iostream>

Snake::Snake(Grid& grid) : grid(grid){

    reset();

}

void Snake::reset(){
    
    while (!body.empty()) {
        grid.updateCell(body.front(), Cell::Type::Empty);
        body.pop_front();
    }
    
    Position head = {grid.getSize() / 2, grid.getSize() / 2};
    Position tail = {head.x - 1, head.y};
    
    body.push_front(tail);
    body.push_front(head);

    grid.updateCell(tail, Cell::Type::SnakeBody);
    grid.updateCell(head, Cell::Type::SnakeHead);

    hasEaten = false;
    gameOver = false;
    currentDirection = Direction::Right;
}

void Snake::move(){
    Position head = body.front();
    
    grid.updateCell(head, Cell::Type::SnakeBody);

    // Update the head's position
    switch (currentDirection) {
        case Direction::Up:    
            head.y -= 1; 
            break;
        case Direction::Down:  
            head.y += 1; 
            break;
        case Direction::Left:  
            head.x -= 1; 
            break;
        case Direction::Right: 
            head.x += 1; 
            break;
    }

    // game over flag
    if(isGameOver(head)){
        gameOver = true;
        return;
    }

    // has eaten flag
    if(grid.getCell(head) == Cell::Type::Food){
        hasEaten = true;
    }

    grid.updateCell(head, Cell::Type::SnakeHead);
    
    body.push_front(head);

    // if the snake didnt eat, remove the tail
    if(!hasEaten){
        grid.updateCell(body.back(), Cell::Type::Empty);
        body.pop_back();
    }

    hasEaten = false;

}

bool Snake::isGameOver(Position newHead){
    // check if head collides with wall or body
    if(grid.getCell(newHead) == Cell::Type::Border || grid.getCell(newHead) == Cell::Type::SnakeBody){
        return true;
    }
    return false;
}


void Snake::setDirection(Direction newDirection){
    
    // only change direction, if it isnt opposite of current direction
    // else the snake would move through itself
    
    if(newDirection == Direction::Left && !(currentDirection == Direction::Right)){
        currentDirection = Direction::Left;
    }
    if(newDirection == Direction::Right && !(currentDirection == Direction::Left)){
        currentDirection = Direction::Right;
    }
    if(newDirection == Direction::Up && !(currentDirection == Direction::Down)){
        currentDirection = Direction::Up;
    }
    if(newDirection == Direction::Down && !(currentDirection == Direction::Up)){
        currentDirection = Direction::Down;
    }
}

bool Snake::getGameOverStatus(){
    return gameOver;
}

int Snake::getScore(){
    return body.size();
}