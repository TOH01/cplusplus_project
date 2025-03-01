#include <SFML/Graphics.hpp>
#include "grid.hpp"
#include "snake.hpp"
#include "constants.hpp"
#include "food.hpp"

int main() {

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT)), "Snake", sf::Style::Titlebar | sf::Style::Close);
    sf::Clock clock;

    Grid grid(GRID_SIZE);
    Snake snake(grid);
    Food food(grid);

    // Main loop
    while (window.isOpen()) {
        // Poll events
        
        sf::Time elapsed = clock.getElapsedTime();

        if (elapsed.asSeconds() >= 0.25f) {  
 
            snake.move();

            clock.restart();
        }
        
        while (const std::optional<sf::Event> event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
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
            }

        }

        grid.draw(window);

        food.respawn();

        window.display();
    }

    return 0;
}
