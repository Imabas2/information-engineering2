#include <iostream>
#include <vector>
#include <memory>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class CustomSprite : public sf::Sprite {
public:
    CustomSprite(){}

    void setSpeed(const int& xspeed, const int& yspeed) {
        xspeed_ = xspeed;
        yspeed_ = yspeed;
    }

    void setBounds(const float& l_bound, const float& r_bound,const float& u_bound,const float& d_bound){
        l_bound_  = l_bound  ;
        r_bound_  = r_bound  ;
        u_bound_  = u_bound  ;
        d_bound_  = d_bound  ;
    }
    void setWallBounds(const float& l_bound, const float& r_bound,const float& u_bound,const float& d_bound){
        wall_l_bound_.emplace_back(l_bound);
        wall_r_bound_.emplace_back(r_bound);
        wall_u_bound_.emplace_back(u_bound);
        wall_d_bound_.emplace_back(d_bound);
    }

    void moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key)
    {
        float dt = elapsed.asSeconds();
        if(key == sf::Keyboard::Up)
        {
            yspeed_ = -1*abs(yspeed_);
            bouncce();

            sf::FloatRect rectangle_bounds = getGlobalBounds();
            for(int i =0;i<=wall_d_bound_.size();i++)
                if(
                        (rectangle_bounds.top < wall_d_bound_[i] && rectangle_bounds.top > wall_u_bound_[i]) &&
                        (rectangle_bounds.left < wall_r_bound_[i] && rectangle_bounds.left + rectangle_bounds.width > wall_l_bound_[i])
                        ){
                    yspeed_ = abs(yspeed_);
                    std::cout << "Colision up" << std::endl;
                }
            move(0,yspeed_*dt);
        }
        else if(key == sf::Keyboard::Down)
        {
            yspeed_ = abs(yspeed_);
            bouncce();

            sf::FloatRect rectangle_bounds = getGlobalBounds();
            for(auto i =0;i<=wall_d_bound_.size();i++)
                if(
                        (rectangle_bounds.top + rectangle_bounds.height > wall_u_bound_[i] && rectangle_bounds.top < wall_d_bound_[i]) &&
                        (rectangle_bounds.left < wall_r_bound_[i] && rectangle_bounds.left + rectangle_bounds.width  > wall_l_bound_[i])
                        ){
                    yspeed_ = abs(yspeed_) * -1;
                    std::cout << "Colision down" << std::endl;
                }
            move(0,yspeed_*dt);
        }
        else if(key == sf::Keyboard::Left)
        {
            xspeed_ = -1*abs(xspeed_);
            bouncce();

            sf::FloatRect rectangle_bounds = getGlobalBounds();
            for(auto i =0;i<=wall_d_bound_.size();i++)
                if(
                        (rectangle_bounds.left < wall_r_bound_[i] && rectangle_bounds.left > wall_l_bound_[i]) &&
                        (rectangle_bounds.top + rectangle_bounds.height > wall_u_bound_[i] && rectangle_bounds.top < wall_d_bound_[i])
                        ){
                    xspeed_ = abs(xspeed_);
                    std::cout << "Colision right" << std::endl;
                }
            move(xspeed_*dt,0);
        }
        else if(key == sf::Keyboard::Right)
        {
            xspeed_ = abs(xspeed_);
            bouncce();

            sf::FloatRect rectangle_bounds = getGlobalBounds();
            for(auto i =0;i<=wall_d_bound_.size();i++)
                if(
                        (rectangle_bounds.left < wall_r_bound_[i] && rectangle_bounds.left + rectangle_bounds.width > wall_l_bound_[i]) &&
                        (rectangle_bounds.top + rectangle_bounds.height > wall_u_bound_[i] && rectangle_bounds.top < wall_d_bound_[i])
                        ){
                    xspeed_ = abs(xspeed_) * -1;
                    std::cout << "Colision left" << std::endl;
                }
            move(xspeed_*dt,0);
        }
    }


private:
    int xspeed_ = 0 ;
    int yspeed_ = 0 ;
    float l_bound_ = 1;
    float r_bound_ = 1;
    float u_bound_ = 1;
    float d_bound_ = 1;

    std::vector<float> wall_l_bound_;
    std::vector<float> wall_r_bound_;
    std::vector<float> wall_u_bound_;
    std::vector<float> wall_d_bound_;


    void bouncce(){
        sf::FloatRect rectangle_bounds = getGlobalBounds();
        std::cout << rectangle_bounds.top << " / " << rectangle_bounds.left << std::endl;

        if(rectangle_bounds.top <= u_bound_)
        {yspeed_ = abs(yspeed_);}

        if(rectangle_bounds.top + rectangle_bounds.height >= d_bound_)
        {yspeed_ = abs(yspeed_) * -1;}

        if(rectangle_bounds.left <= l_bound_ )
        {xspeed_ = abs(xspeed_);}

        if(rectangle_bounds.left + rectangle_bounds.width >= r_bound_)
        {xspeed_ = abs(xspeed_) * -1;}
    }

};


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::Texture texture_bg;
    sf::Texture texture_guy;
    sf::Texture texture_wall;

    if(!texture_bg.loadFromFile("grass.png")) {std::cerr << "Could not load texture" << std::endl; }//return 0;
    if(!texture_guy.loadFromFile("guy.png")) {std::cerr << "Could not load texture" << std::endl; }//return 0;
    if(!texture_wall.loadFromFile("wall.png")) {std::cerr << "Could not load texture" << std::endl;}// return 0;


    texture_bg.setRepeated(true);
    sf::Sprite sprite_bg;
    sprite_bg.setTexture(texture_bg);
    sprite_bg.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));


    CustomSprite guy;
    guy.setPosition(1.0,1.0);
    guy.setTexture(texture_guy);


    texture_wall.setRepeated(true);
    sf::Sprite wall;
    wall.setTexture(texture_wall);
    wall.setTextureRect(sf::IntRect(0, 0, 50, 250));
    wall.setPosition(60.0,100.0);

    sf::Sprite wall2;
    wall2.setTexture(texture_wall);
    wall2.setTextureRect(sf::IntRect(0, 0, 50, 300));
    wall2.setPosition(200.0,200.0);

    sf::Sprite wall3;
    wall3.setTexture(texture_wall);
    wall3.setTextureRect(sf::IntRect(20, 10, 145, 50));
    wall3.setPosition(350.0,75.0);

    sf::Sprite wall4;
    wall4.setTexture(texture_wall);
    wall4.setTextureRect(sf::IntRect(0, 0, 100, 190));
    wall4.setPosition(400.0,200.0);

    sf::Sprite wall5;
    wall5.setTexture(texture_wall);
    wall5.setTextureRect(sf::IntRect(0, 0, 100, 180));
    wall5.setPosition(40.0,360.0);

    sf::Sprite wall6;
    wall6.setTexture(texture_wall);
    wall6.setTextureRect(sf::IntRect(0, 0, 170, 70));
    wall6.setPosition(570.0,180.0);

    sf::Clock clock;


    guy.setBounds(0, window.getSize().x, 0, window.getSize().y);
    guy.setWallBounds(wall.getGlobalBounds().left , wall.getGlobalBounds().left + wall.getTextureRect().width ,wall.getGlobalBounds().top , wall.getGlobalBounds().top + wall.getTextureRect().height);
    guy.setWallBounds(wall2.getGlobalBounds().left , wall2.getGlobalBounds().left + wall2.getTextureRect().width ,wall2.getGlobalBounds().top , wall2.getGlobalBounds().top + wall2.getTextureRect().height);
    guy.setWallBounds(wall3.getGlobalBounds().left , wall3.getGlobalBounds().left + wall3.getTextureRect().width ,wall3.getGlobalBounds().top , wall3.getGlobalBounds().top + wall3.getTextureRect().height);
    guy.setWallBounds(wall4.getGlobalBounds().left , wall4.getGlobalBounds().left + wall4.getTextureRect().width ,wall4.getGlobalBounds().top , wall4.getGlobalBounds().top + wall4.getTextureRect().height);
    guy.setWallBounds(wall5.getGlobalBounds().left , wall5.getGlobalBounds().left + wall5.getTextureRect().width ,wall5.getGlobalBounds().top , wall2.getGlobalBounds().top + wall5.getTextureRect().height);
    guy.setWallBounds(wall6.getGlobalBounds().left , wall6.getGlobalBounds().left + wall6.getTextureRect().width ,wall6.getGlobalBounds().top , wall2.getGlobalBounds().top + wall6.getTextureRect().height);
    std::cout << wall.getGlobalBounds().left <<"/"<< wall.getGlobalBounds().left + wall.getTextureRect().width <<"/"<<wall.getGlobalBounds().top <<"/"<< wall.getGlobalBounds().top + wall.getTextureRect().height;

    guy.setSpeed(100.0,100.0);
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){ guy.moveInDirection(elapsed,sf::Keyboard::Right);}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){ guy.moveInDirection(elapsed,sf::Keyboard::Left);}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){ guy.moveInDirection(elapsed,sf::Keyboard::Up);}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){ guy.moveInDirection(elapsed,sf::Keyboard::Down);}

        window.clear(sf::Color::Black);

        window.draw(sprite_bg);
        std::vector<sf::Sprite> walls = {wall, wall2, wall3, wall4,  wall5, wall6};
        for( auto wa : walls ) {
            window.draw(wa);
        }
        window.draw(guy);
        window.display();
    }

    return 0;
}
