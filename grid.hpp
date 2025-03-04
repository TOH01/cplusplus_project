#pragma once

#include <SFML/Graphics.hpp>
#include "cell.hpp"
#include <vector>

class Grid {
    public:
        Grid(int size);
        
        void draw(sf::RenderWindow & window);
        void updateCell(Position position, Cell::Type newType);
        int getSize();
        Cell::Type getCell(Position position);
    private:
        int currentSize;
        std::vector<std::vector<Cell>> grid;
};