#include <iostream>
#include <vector>

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

    void setBounds(const float& l_bound, const float& r_bound,const float& u_bound,const float& d_bound){
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

    bool isActive(){return active_;}
    void makeActive(){
        setFillColor(sf::Color(255,0,0));
        active_ = true;
    }
    void disactivate(){
        setFillColor(sf::Color(0,255,0));
        active_ = false;
    }

private:
    int x_speed_ = 0 ;
    int y_speed_ = 0 ;
    int ro_speed_ = 0 ;
    float l_bound_ = 0;
    float r_bound_ = 0;
    float u_bound_ = 0;
    float d_bound_ = 0;
    bool active_ = 0;

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
    std::srand(std::time(nullptr));

    std::vector<CustomRectangleShape> rectangles;

    for(int i=0; i<10; i++)
    {
        sf::Vector2f size(120.0, 60.0);
        sf::Vector2f position(std::rand() % (window.getSize().x - 120), std::rand() % (window.getSize().y - 60));
        rectangles.emplace_back(CustomRectangleShape(size, position));
    }

    for(auto &rec : rectangles)
    {
        rec.setFillColor(sf::Color(0, 255, 0));
        rec.setBounds(0, window.getSize().x, 0, window.getSize().y);
        rec.setSpeed(100, 200, 10);
    }

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2i mouse_pos;
        if(event.type == sf::Event::MouseButtonPressed)
        {
            if(event.mouseButton.button == sf::Mouse::Left)
                 mouse_pos = sf::Mouse::getPosition(window);

            for(auto &rec : rectangles)
            {
                rec.disactivate();
                if(rec.isClicked(mouse_pos))
                    rec.makeActive();
            }
        }


        sf::Keyboard::Key pressed;
        if(event.type == sf::Event::KeyPressed)
        {
            pressed = event.key.code;
            for(auto &rec : rectangles)
            {
                if(rec.isActive())
                    rec.moveInDirection(elapsed,pressed);
            }

        }


        window.clear(sf::Color::Black);
        for(auto &rec : rectangles)
        {
            window.draw(rec);
        }
        window.display();
    }

    return 0;
}
