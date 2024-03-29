
/*
A fold expression is an instruction for the compiler to repeat the
application of an operator over a variadic template pack.


*/
#include <iostream>

using namespace std;

#include <iostream>
#include <string>

using namespace std;
 
template<typename ...Args> auto sum(Args ...args) 
{ 
    return (args + ... + 0); 
}

template<typename ...Args> auto sum2(Args ...args) 
{ 
    return (args + ...);
}

int main()
{
    cout << sum(1, 2, 3, 4, 5, 6, 7) << "\n";
	cout << sum2(1, 2, 3, 4, 5, 6, 7) << "\n";
}