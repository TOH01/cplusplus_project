#include <cstdlib>
#include <ctime>
#include "food.hpp"

Food::Food(Grid& grid) : grid(grid){
    position = {1, 1}; // need to init position, since it will cause segfault when calling respawn() for the first time
    srand(time(0));
    respawn();
}

void Food::respawn(){
    
    // only respawn if food has been eaten
    // do not need to delete the food field, since snake moving over it will reset it already

    if(grid.getCell(position) != Cell::Type::Food){
        while (true)
        {
            
            //  make it so food cant spawn on borders
            int x = (rand() % (grid.getSize() - 2)) + 1;
            int y = (rand() % (grid.getSize() - 2)) + 1;

    
            if(grid.getCell({x, y}) != Cell::Type::SnakeBody && grid.getCell({x, y}) != Cell::Type::SnakeHead){
                grid.updateCell({x, y}, Cell::Type::Food);
                position = {x, y};
                break;
            }
        }
    }


    
}