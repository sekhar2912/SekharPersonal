#include <iostream>
#include <iomanip>
#include <utility>

using namespace std;

class TestString
{
    private:
    std::string s{};
    int i{-1};

    public:
    TestString() : s("Test"),i(0)
    { }

    TestString(const TestString& o) : s(o.s),i(o.i) 
    {
        std::cout << "Copy Constructor" << std::endl;
    }
    TestString(TestString&& o) noexcept : s(std::move(o.s)),i(std::exchange(o.i,0)) 
    {
        std::cout << "Move Constructor" << std::endl;
    }

    TestString& operator+(TestString&& o)
    {
        s = std::move(o.s);
        i = std::exchange(o.i,0);
        return *this;

    }
};

TestString f(TestString a)
{
    return a;
}


int main()
{
    TestString os_1 = f(TestString());
    TestString os_2 = std::move(os_1);
    return 0;
}