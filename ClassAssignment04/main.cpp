#include <iostream>
#include<vector>
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

    void setBounds(const double& left_bound, const double& right_bound,const double& up_bound,const double& down_bound){
        left_bound_  = left_bound  ;
        right_bound_  = right_bound  ;
        up_bound_  = up_bound  ;
        down_bound_  = down_bound  ;
    }

    void moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key)
    {
        float dt = elapsed.asSeconds()*150;
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

    void select()
    {
        selected = true;
    }

    void unselect()
    {
        selected = false;
    }

    bool isSelected()
    {
        return selected;
    }


private:
    int x_speed_ = 10 ;
    int y_speed_ = 10 ;
    int ro_speed_ = 0 ;
    float left_bound_ = 0;
    float right_bound_ = 0;
    float up_bound_ = 0;
    float down_bound_ = 0;
    bool selected = false;

    void bouncce(){
        sf::FloatRect rectangle_bounds = getGlobalBounds();

        if(rectangle_bounds.top <= up_bound_){
            y_speed_ = abs(y_speed_);
        }

        if(rectangle_bounds.top + rectangle_bounds.height >= down_bound_){
            y_speed_ = abs(y_speed_) * -1;
        }

        if(rectangle_bounds.left <= left_bound_ ){
            x_speed_ = abs(x_speed_);
        }

        if(rectangle_bounds.left + rectangle_bounds.width >= right_bound_){
            x_speed_ = abs(x_speed_) * -1;
        }
    }

};


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::Vector2f size(100.0, 60.0);
    std::vector<CustomRectangleShape> rectangles;
    //Rectangles
    for(int i = 0; i<15; i++) {
        sf::Vector2f position(rand() % 600, rand() % 400);
        CustomRectangleShape rectangle_inh(size, position);
        rectangle_inh.setFillColor(sf::Color(0, 250, 0));
        rectangle_inh.setSpeed(100, 200, 10);
        rectangles.push_back(rectangle_inh);
    }


    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();

        for( auto &rectangle : rectangles){
            rectangle.setBounds(0, window.getSize().x, 0, window.getSize().y);
        }


        sf::Event event;
        while (window.pollEvent(event)) {
            sf::Keyboard::Key pressed;
            sf::Vector2i mouse_pos;

            if(event.type == sf::Event::KeyPressed)
            {
                pressed = event.key.code;
                for( auto &rectangle : rectangles){
                    if( rectangle.isSelected() ) {
                        rectangle.moveInDirection(elapsed,pressed);
                    }
                }
            }

            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                mouse_pos = sf::Mouse::getPosition(window);
                for( auto &rectangle : rectangles){
                    if(rectangle.isClicked(mouse_pos)) {
                        if(rectangle.isSelected()) {
                            rectangle.unselect();
                            rectangle.setFillColor(sf::Color(0, 250, 0));
                        } else {
                            rectangle.select();
                            rectangle.setFillColor(sf::Color(250,0,0));
                        }
                    } else {
                        rectangle.unselect();
                        rectangle.setFillColor(sf::Color(0, 250, 0));
                    }
                }
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }




        window.clear(sf::Color::Black);
        for( auto &rectangle : rectangles ) {
            window.draw(rectangle);
        }
        window.display();
    }

    return 0;
}
