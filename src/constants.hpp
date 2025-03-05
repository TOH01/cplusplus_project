#pragma once

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

#define GRID_SIZE 20

#define BORDER_COLOR sf::Color(87, 138, 52)
#define EMPTY_COLOR_1 sf::Color(170, 215, 81)
#define EMPTY_COLOR_2 sf::Color(162, 209, 73)
#define SNAKE_BODY_COLOR sf::Color(78, 124, 246)
#define SNAKE_HEAD_COLOR sf::Color(66, 111, 226)
#define FOOD_COLOR sf::Color(231, 71, 29)

struct Position{
    int x, y;
};