#include <iostream>
#include <vector>

class Item{
public:
    std::string name;
    float price;
    char vat;
    float amount;


    Item(std::string n="",float p=0, char v=' ', float a=0.0);
    std::string get_name();
    float get_price();
    char get_vat();
    float get_amount();

};

class Invoice{
public:
    std::string NIP_s;
    std::string NIP_b;
    std::vector<Item> items;

public:
    Invoice(std::string s="0", std::string b="0");

    void add_item(const Item &item);


};
