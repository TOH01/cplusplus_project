#pragma once

#include "grid.hpp"

class Food {
    public:
        Food(Grid & grid);
        void respawn();
    private:
        Grid& grid;
        Position position;
};