#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;


class Comparator
{
    public:

    bool compare(int a, int b)
    {
        return (a==b);
    }
    
    bool compare(string a, string b)
    {
        return verify(a,b);
    }

    bool compare(int a[], int b[])
    {
         return verify(a,b);
    }

    public:
    template<typename T>
    bool verify(T a, T b)
    {
        int aSize = sizeof(a)/sizeof(a[0]);
        int bSize = sizeof(b)/sizeof(b[0]);
        if(aSize != bSize) return false;
        for(int i =0 ;i< aSize;++i)
         if (a[i] != b[i]) return false;
        
        return true;
    }
}; 


int main ()
{
    return 0;
}