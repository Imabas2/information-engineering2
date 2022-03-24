#include <iostream>
#include <copyAD.h>

int main()
{
    Time t1(200);
    std::cout << t1 << std::endl; // displays 03m:20s
    Time t2;
    std::cin >> t2; // user enters 10h:12m:01s

    Time t3 = t2 - t1; // 10h:8m:41s
    int t3s = t3; // 36521
    std::cout << t3s << std::endl;

   }
