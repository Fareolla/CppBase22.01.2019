#include <iostream>
#include <cmath>

int main()
{
     double a, b, c, D, x;
     std::cout << " ax2 + bx + c = 0 " << std::endl;
     std::cout << "Please insert a" << std::endl;
     std::cin >> a;
     std::cout << "Please insert b" << std::endl;
     std::cin >> b;
     std::cout << "Please insert c" << std::endl;
     std::cin >> c;
     D = b * b - 4 * a * c;
     if (D >= 0)
     {
         x = (-1*b + sqrt(D)) / (2 * a);
         std::cout << "First root is: " << x << std::endl;
         x = (-1*b - sqrt(D)) / (2 * a);
         std::cout << "Second root is: " << x << std::endl;
     }
     else
     {
        std::cout << "D < 0. No decisions!" << std::endl;
     }
    return 0;
}
