#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class CustomRectangleShape : public sf::RectangleShape {
public:
    CustomRectangleShape(const sf::Vector2f &size, const sf::Vector2f &position) : sf::RectangleShape(size)
    {
        setPosition(position);
    }

    void setSpeed(const int& x_speed, const int& y_speed, const int & ro_speed) {
        x_speed_ = x_speed;
        y_speed_ = y_speed;
        ro_speed_ = ro_speed;
    }

    void setBounds(const double& l_bound, const double& r_bound,const double& u_bound,const double& d_bound){
        l_bound_  = l_bound  ;
        r_bound_  = r_bound  ;
        u_bound_  = u_bound  ;
        d_bound_  = d_bound  ;
    }

    void moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key)
    {
        float dt = elapsed.asSeconds();
        if(key == sf::Keyboard::Up)
        {
            y_speed_ = -1*abs(y_speed_);
            bouncce();
            move(0,y_speed_*dt);
        }
        if(key == sf::Keyboard::Down)
        {
            y_speed_ = abs(y_speed_);
            bouncce();
            move(0,y_speed_*dt);
        }
        if(key == sf::Keyboard::Left)
        {
            x_speed_ = -1*abs(x_speed_);
            bouncce();
            move(x_speed_*dt,0);
        }
        if(key == sf::Keyboard::Right)
        {
            x_speed_ = abs(x_speed_);
            bouncce();
            move(x_speed_*dt,0);
        }
    }

    bool isClicked(sf::Vector2i &mouse_position) const
    {
        sf::FloatRect rectangle_bounds = getGlobalBounds();

        if(mouse_position.x >= rectangle_bounds.left &&
           mouse_position.x <= rectangle_bounds.left+ rectangle_bounds.width &&
           mouse_position.y >= rectangle_bounds.top &&
           mouse_position.y <= rectangle_bounds.top+ rectangle_bounds.height)
            return true;
        return false;
    }

private:
    int x_speed_ = 0 ;
    int y_speed_ = 0 ;
    int ro_speed_ = 0 ;
    float l_bound_ = 0;
    float r_bound_ = 0;
    float u_bound_ = 0;
    float d_bound_ = 0;

    void bouncce(){
        sf::FloatRect rectangle_bounds = getGlobalBounds();

        if(rectangle_bounds.top <= u_bound_){
            y_speed_ = abs(y_speed_);
        }

        if(rectangle_bounds.top + rectangle_bounds.height >= d_bound_){
            y_speed_ = abs(y_speed_) * -1;
        }

        if(rectangle_bounds.left <= l_bound_ ){
           x_speed_ = abs(x_speed_);
        }

        if(rectangle_bounds.left + rectangle_bounds.width >= r_bound_){
            x_speed_ = abs(x_speed_) * -1;
        }
    }

};


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::Vector2f size(120.0, 60.0);
    sf::Vector2f position(120.0, 60.0);
    CustomRectangleShape rectangle_inh(size, position);
    rectangle_inh.setFillColor(sf::Color(150, 100, 50));
    rectangle_inh.setSpeed(100, 150, 10);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();

        rectangle_inh.setBounds(0, window.getSize().x, 0, window.getSize().y);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        sf::Keyboard::Key pressed;
        sf::Vector2i mouse_pos;

        if(event.type == sf::Event::KeyPressed)
        {
            pressed = event.key.code;
            rectangle_inh.moveInDirection(elapsed,pressed);
        }

        if(event.type == sf::Event::MouseButtonPressed)
            if(event.mouseButton.button == sf::Mouse::Left)
                 mouse_pos = sf::Mouse::getPosition(window);

        if(rectangle_inh.isClicked(mouse_pos))
            rectangle_inh.setFillColor(sf::Color(rand() % 256,rand() % 256,rand() % 256));



        window.clear(sf::Color::Black);
        window.draw(rectangle_inh);
        window.display();
    }

    return 0;
}
