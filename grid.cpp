#include <SFML/Graphics.hpp>
#include "grid.hpp"
#include "constants.hpp"

Grid::Grid(int size){
    currentSize = size;
    
    //create grid, cell constructor automatically sets all to empty
    grid.resize(size, std::vector<Cell>(size));


    //set all border cells to border type
    for (size_t y = 0; y < currentSize; y++)
    {
        for (size_t x = 0; x < currentSize; x++)
        {
        
            if(x == 0 || y == 0 || y == size -1 || x == size - 1){
                grid[x][y].setType(Cell::Type::Border);
            }

        }
        
    }

}

void Grid::draw(sf::RenderWindow & window){
    
    window.clear();  

    for (int y = 0; y < currentSize; y++)
    {
        for (int x = 0; x < currentSize; x++)
        {
        
            sf::RectangleShape square(sf::Vector2f(WINDOW_WIDTH / currentSize, WINDOW_HEIGHT / currentSize));
            
            square.setPosition(sf::Vector2f((WINDOW_WIDTH / currentSize) * x, (WINDOW_HEIGHT / currentSize) * y));
            
            square.setFillColor(grid[x][y].getColor({x, y}));
            
            window.draw(square);

        }
        
    }
    
}

void Grid::updateCell(Position position, Cell::Type newType){
    grid[position.x][position.y].setType(newType);
}

int Grid::getSize(){
    return currentSize;
}

Cell::Type Grid::getCell(Position position){
    return grid[position.x][position.y].getType();
}