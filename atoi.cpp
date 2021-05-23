#include <iostream>
#include <sstream>

using namespace std;
int myAtoi(string s) {
        stringstream geek(s);
        int x = 0;
        geek >> x;
        return x;
    }

int main()
{
    std::cout << myAtoi("123") <<std::endl;
    return 0;
}