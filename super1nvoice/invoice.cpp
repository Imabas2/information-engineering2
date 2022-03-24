#include <iostream>
#include <invoice.h>
#include <vector>

Item::Item(std::string n, float p, char v, float a){
    name=n;
    price=p;
    vat=v;
    amount=a;
}

Invoice::Invoice(std::string s, std::string b){
    NIP_s=s;
    NIP_b=b;
}

void Invoice::add_item(const Item &item)
{
    items.emplace_back(item);
}

std::string Item::get_name(){
    return name;
}

float Item::get_price(){
    return price;
};

char Item::get_vat(){
    return vat;
};

float Item::get_amount(){
    return amount;
};
