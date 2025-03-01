#include "snake.hpp"
#include <iostream>

Snake::Snake(Grid& grid) : grid(grid){

    Position head = {grid.getSize() / 2, grid.getSize() / 2};
    Position tail = {head.x - 1, head.y};
    
    body.push_front(tail);
    body.push_front(head);

    grid.updateCell(tail, Cell::Type::SnakeBody);
    grid.updateCell(head, Cell::Type::SnakeHead);

    hasEaten = false;
    currentDirection = Direction::Right;

}

void Snake::move(){
    Position head = body.front();
    
    grid.updateCell(head, Cell::Type::SnakeBody);

    switch (currentDirection) {
        case Direction::Up:    head.y -= 1; break;
        case Direction::Down:  head.y += 1; break;
        case Direction::Left:  head.x -= 1; break;
        case Direction::Right: head.x += 1; break;
    }

    if(gameOver(head)){
        std::cout << "Game Over!" << std::endl;
        return;
    }

    if(grid.getCell(head) == Cell::Type::Food){
        hasEaten = true;
    }

    grid.updateCell(head, Cell::Type::SnakeHead);
    
    body.push_front(head);

    if(!hasEaten){
        grid.updateCell(body.back(), Cell::Type::Empty);
        body.pop_back();
    }

    hasEaten = false;

}

bool Snake::gameOver(Position newHead){
    if(grid.getCell(newHead) == Cell::Type::Border || grid.getCell(newHead) == Cell::Type::SnakeBody){
        return true;
    }
    return false;
}

void Snake::setDirection(Direction newDirection){
    
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