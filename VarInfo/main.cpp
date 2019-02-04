#include <iostream>
#include "varinfo.h"

int main()
{
char choice;
bool run = true;
while(run)
{
    int key;
    std::cout << " Select a number to get information about min / max values and size of:" <<std::endl;
    std::cout << "   1.  bool " <<std::endl;
    std::cout << "   2.  char " <<std::endl;
    std::cout << "   3.  short " <<std::endl;
    std::cout << "   4.  int " <<std::endl;
    std::cout << "   5.  long " <<std::endl;
    std::cout << "   6.  float " <<std::endl;
    std::cout << "   7.  double " <<std::endl;
     while(!(std::cin >> key)) // проверяет соответствуют ли вводимые данные ожидаемому типу или нет.
    {
        std::cin.clear(); // восстанавливает поток, если что-то пошло не так. В данном случае хотим получить число, а получили символ. Поток впадает в ступор Чтобы восстановить работу потока мы вызываем cin.clear().
        while (std::cin.get() != '\n'); // получает значение из потока данных.
        std::cout << "Please enter numbers only!" << std::endl;
    }
    VarInfo::Info(key);
    std::cout << std::endl;
    do
    {
        std::cout<<"Would you like to select other type?(Y/N)"<<std::endl;
        std::cin >> choice;
        choice = tolower(choice); //Сделать буквы в нижнем регистре
    }while (choice != 'n' && choice != 'y');
    if(choice =='n')
        {
            run = false;
        }
}

return 0;
}
