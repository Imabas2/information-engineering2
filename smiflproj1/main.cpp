#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");//RenderWindow=class,window=obj

    // create some shapes


    sf::CircleShape circle(100.0);
    sf::CircleShape circle2(50.0);
    sf::CircleShape circle3(30.0);
    circle.setPosition(100.0, 300.0);
    circle2.setPosition(100.0, 100.0);
    circle3.setPosition(50.0, 50.0);

    circle.setFillColor(sf::Color(100, 250, 50));
    circle2.setFillColor(sf::Color(100, 150, 50));
    circle3.setFillColor(sf::Color(80, 100, 60));

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(5);
    triangle.setPosition(600.0, 100.0);

//    int rectangle_velocity_x=50;
//    int rectangle_velocity_y=150;

     sf::CircleShape square(80.f, 4);

    // run the program as long as the window is open

     sf::Clock clock;
    while (window.isOpen()) {
        sf::Clock clock;

        int rectangle_velocity_x = 5;
        int rectangle_velocity_y = 15;
        int rectangle_angular_velocity = 10;

        bool flag_y = false;
        bool flag_x = false;


        // run the program as long as the window is open
        while (window.isOpen()) {
            sf::Time elapsed = clock.restart();
            float dt = elapsed.asSeconds();

            rectangle.move(rectangle_velocity_x*dt,rectangle_velocity_y*dt);
            rectangle.rotate(rectangle_angular_velocity*dt);

            sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();
            std::cout << rectangle_bounds.top << " " << rectangle_bounds.left << " " ;
            std::cout << rectangle_bounds.width << " " << rectangle_bounds.height << std::endl;

            if(rectangle_bounds.top<=0 || rectangle_bounds.top+rectangle_bounds.height>=window.getSize().y)
                {
                    if(flag_y != true)
                    {
                        rectangle_velocity_y *= -1;
                        rectangle.setFillColor(sf::Color(rand() % 256,
                                                         rand() % 256,
                                                         rand() % 256));
                    }
                    flag_y = true;
                }
                else
                    flag_y = false;



                if(rectangle_bounds.left<=0 || rectangle_bounds.left+rectangle_bounds.width>=window.getSize().x)
                {
                    if(flag_x!=true)
                    {
                        rectangle_velocity_x *= -1;
                        rectangle.setFillColor(sf::Color(rand() % 256,
                                                         rand() % 256,
                                                         rand() % 256));
                    }
                    flag_x = true;
                }
                else
                    flag_x = false;
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);
        window.draw(circle2);
        window.draw(circle3);

        // end the current frame
        window.display();
    }

return 0;
}
}


using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
