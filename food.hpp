#pragma once

#include "grid.hpp"
#include <SFML/Audio.hpp>

class Food {
    public:
        Food(Grid & grid);
        void respawn();
        void reset();
    private:
        Grid& grid;
        Position position;
        sf::SoundBuffer buffer;
        sf::Sound * eatSound; // need to save as pointer or else get - error: no matching function for call to 'sf::Sound::Sound()
};