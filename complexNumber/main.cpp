#include <iostream>
#include <complex>
using namespace std;

class Complex{
private:
     float iNumber=0.0;
     float rNumber=0.0;
public:
     Complex(float rNumberNew,float iNumberNew)
     {
     iNumber=iNumberNew;
     rNumber=rNumberNew;
     }
     Complex(float rNumberNew)
     {
        rNumber=rNumberNew;
     }
    void set_im(float a1)
    {
        iNumber = a1;
    }
    void set_rNumber(float a2)
    {
        rNumber =a2;
    }
    float get_rNumber(){
        return rNumber;
    }
    void printRealpart()
    {
        cout << rNumber;
    }
    void printImaginary()
    {
        cout << iNumber << "i" ;
    }
    float get_iNumber()
    {
        return iNumber;
    }
    void print() {
        cout << rNumber << iNumber << "i";
    }
    Complex add(Complex b)
    {
       float cINumber = iNumber+b.iNumber;
       float cRNumber = rNumber +b.rNumber;
    Complex C(cRNumber,cINumber );
    return C;
    }
};

int main()
{
    Complex a(1.0, -2.0); // creates 1-2i
    Complex b(3.14); // creates 3.14

    b.set_im(-5);

    Complex c = a.add(b);

    c.print(); // prints 4.14-7i
}
