#include <cstdlib>
#include <ctime>
#include <iostream>
#include "food.hpp"

Food::Food(Grid& grid) : grid(grid), position({-1, -1}){

    reset();

    if (!buffer.loadFromFile("../assets/echo_pop.wav")){
        std::cerr << "Couldnt load echo_pop.wav" << std::endl;
    }

    eatSound = new sf::Sound(buffer);

    eatSound->setVolume(100);
    
}

void Food::reset(){
    
    //contructor will init food to -1, -1
    if(position.x != -1 && position.y != -1){
        grid.updateCell(position, Cell::Type::Empty);
    }
    
    position = {grid.getSize() / 2 + grid.getSize() / 4, grid.getSize() / 2};
    grid.updateCell(position, Cell::Type::Food);
}

void Food::respawn(){
    
    // only respawn if food has been eaten
    // do not need to delete the food field, since snake moving over it will reset it already

    if(grid.getCell(position) != Cell::Type::Food){
        
        eatSound->play();

        while (true)
        {
            
            //  make sure food doesnt spawn on borders
            int x = (rand() % (grid.getSize() - 2)) + 1;
            int y = (rand() % (grid.getSize() - 2)) + 1;


            // make sure food doesnt spawn on snake
            if(grid.getCell({x, y}) != Cell::Type::SnakeBody && grid.getCell({x, y}) != Cell::Type::SnakeHead){
                grid.updateCell({x, y}, Cell::Type::Food);
                position = {x, y};
                break;
            }
        }
    }


    
}