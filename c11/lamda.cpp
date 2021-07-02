/*
Lamda Function Demostration in C++

Important Pt - The empty capture clause, takes global parameter by refference

*/

#include <iostream>

using namespace std;
std::string global{"Hello World"};

auto printName = [](int x, int& y)-> std::string
                  {
                   global = "Hello changed";
                   std::cout << "Refference -" << y <<"Global -" <<  global << std::endl;
                   return global;
                  };

int main()
{

   int y = 2;
    std::string tobePrinted = printName(1,y);
    std::cout <<"Is Global Changed -" <<global;
    return 0;
}
