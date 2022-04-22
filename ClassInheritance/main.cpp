#include<iostream>
#include<string>

class Vehicle {

public:
    std::string V_name() { return name_; }
    int V_wheels() { return number_of_wheels_; }
    std::string propulsion_type() { return propulsion_type_; }
    double max_speed() { return max_speed_; }
    double min_speed(){return min_speed()_}

protected:
    Vehicle(const std::string &name, int number_of_wheels,
            const std::string &propulsion_type, double max_speed)
      : name_(name), number_of_wheels_(number_of_wheels),
        propulsion_type_(propulsion_type), max_speed_(max_speed) 0{}

    std::string name_;
    int number_of_wheels_;
    std::string propulsion_type_;
    double max_speed_;
};
class Bike : public Vehicle {

public:
    Bike() : Vehicle("Bike", 2, "Muscles", 30) {}
};

class Car : public Vehicle {

public:
    Car(const std::string &name, const std::string &propulsion_type,
        double max_speed, bool has_abs)
        : Vehicle(name, 4, propulsion_type, max_speed),
          has_abs_(has_abs) {}

    bool has_abs() { return has_abs_; }

private:
    bool has_abs_;
};

class F1:public Car{
public:
    F1(const string name, const std::float max_speed, float service_time):
        Car(name,"benzin",max_speed,true),
        service_time

};



int main(){




}
