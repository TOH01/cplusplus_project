#include <SFML/Graphics.hpp>
#include "grid.hpp"
#include "snake.hpp"
#include "constants.hpp"
#include "food.hpp"
#include <iostream>

bool gameOver = false;
bool requestRestart = false;

int main() {

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT)), "Snake", sf::Style::Titlebar | sf::Style::Close);
    sf::Clock clock;

    int score = 0;

    sf::Font font;
    if (!font.openFromFile("../assets/Roboto_Condensed-Black.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }

    sf::Text text(font);

    Grid grid(GRID_SIZE);
    Snake snake(grid);
    Food food(grid);

    // seeding for random food generation
    srand(time(0));

    // Main loop
    while (window.isOpen()) {
        
        window.clear(); 
        
        sf::Time elapsed = clock.getElapsedTime();

        // move snake every 0.25 seconds if not  game over
        if (!gameOver && elapsed.asSeconds() >= 0.25f) {  
 
            snake.move();

            gameOver = snake.getGameOverStatus();

            score = snake.getScore();

            clock.restart();
        }

        grid.draw(window);

        food.respawn();

        // handle game over and restart
        if(gameOver){
            
            std::string message = "Game Over\nPress 'Enter' or 'Space' to play again\nScore: " + std::to_string(score);
            
            text.setString(message);
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::Red);

            text.setPosition({WINDOW_WIDTH / 3, WINDOW_HEIGHT / 3});

            window.draw(text);
            
            if(requestRestart){
                gameOver = false;
                requestRestart = false;

                snake.reset();
                food.reset();
            }
        }
        
        // poll events
        while (const std::optional<sf::Event> event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            // handle snake movement and restart mechanic
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::W || keyPressed->scancode == sf::Keyboard::Scancode::Up){
                    snake.setDirection(Snake::Direction::Up);
                }
                if (keyPressed->scancode == sf::Keyboard::Scancode::S || keyPressed->scancode == sf::Keyboard::Scancode::Down){
                    snake.setDirection(Snake::Direction::Down);
                }
                if (keyPressed->scancode == sf::Keyboard::Scancode::D || keyPressed->scancode == sf::Keyboard::Scancode::Right){
                    snake.setDirection(Snake::Direction::Right);
                }
                if (keyPressed->scancode == sf::Keyboard::Scancode::A || keyPressed->scancode == sf::Keyboard::Scancode::Left){
                    snake.setDirection(Snake::Direction::Left);
                }
                if (keyPressed->scancode == sf::Keyboard::Scancode::Enter || keyPressed->scancode == sf::Keyboard::Scancode::Space){
                    requestRestart = true;
                }
            }

        }

        window.display();
    }

    return 0;
}
