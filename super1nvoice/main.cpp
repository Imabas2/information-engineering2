#include <iostream>
#include <invoice.h>

std::ostream &operator<<(std::ostream &str, Invoice &rhs){

    float net_sum=0;
    float total=0;
    float i=0;

    str << "---------VAT invoice--------------------------\n";
    str << "==============================================\n";
    str << "Seller:"<<rhs.NIP_s<<" "<< "Buyer:"<< rhs.NIP_b <<"\n";
    str << "                  c.j. VAT   il.    net   total\n";
    for(int j=0;  j < rhs.items.size(); j++)
    {
        Item item = rhs.items[j];
        float p_net = item.get_price()*item.get_amount();
        float p_vat=0;

        if(item.get_vat() == 'A') p_vat = p_net*1.23;
        else if(item.get_vat() == 'B') p_vat = p_net*1.08;
        else if(item.get_vat() == 'C') p_vat = p_net;

    str << i<<'.'<<item.get_name()<<"       | "<<item.get_price()<<" "<<item.get_vat()<<" | "<<item.get_amount()<<" | "<<p_net<<" | " <<p_vat<<'\n';
        net_sum+=p_net;
        total+=p_vat;
        i++;
    }

    str << " \n.......................TOTAL ......\n "
        << "                 " <<net_sum<<'|'<<total;

    return str;
}

int main()
{

    std::cout << "\n\n";
    Invoice inv("7770003699", "0123456789");
    inv.add_item(Item("M3 screw", 0.37, 'A', 100));
    inv.add_item(Item("2 mm drill", 2.54, 'B', 2));
    std::cout << inv << std::endl;
}
