#include <iostream>
#include <iomanip>
#include "mylib.h"

int main()
{

    double number, step;
    std::cout << "Please enter a number" << std::endl;
    // проверяет соответствуют ли вводимые данные ожидаемому типу или нет.
    while(!(std::cin >> number))
    {
        // восстанавливает поток, если что-то пошло не так. В данном случае хотим получить число, а получили символ. Поток впадает в ступор Чтобы восстановить работу потока мы вызываем cin.clear()
        std::cin.clear();
        // получает значение из потока данных.
        while (std::cin.get() != '\n');
        std::cout << "Error! Please enter a number not a char!" << std::endl;
    }
    std::cout << "Please enter an exponent" << std::endl;
    while(!(std::cin >> step))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Error! Please enter a number not a char!" << std::endl;
    }
    std::cout << std::setprecision(8) << "Result of exponentiation is: " << Mylib::Exponentiation(number, step) << std::endl;
    return 0;

}
