/*

Description: Given a String s, a sub-string is defined as a non-empty 
string that can be obtained by applying following operation

Remove zero or 1 character from left side of s
Remove zero or 1 character from right side of s
Remove zero or 1 character from left & right side of s
Find how many distinct sub-string possible.
Characters in string are [a-z]
String length can be up to 10^5

*/

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

std::set<std::string> seen{};

long substringCalculator(std::string s, int cnt)
{

    if ((seen.find(s) != seen.end()) || s.length() == 0) // Element present in set or len is 0
        return 0;

    if (!(seen.find(s) != seen.end()))
        seen.insert(s);
    if (s.length() == 1)
        return 1;
    return (1 + substringCalculator(s.substr(0, s.length() - 1), cnt) +
            substringCalculator(s.substr(1, s.length()), cnt)) +
           substringCalculator(s.substr(1, s.length() - 1), cnt);
}

long substringCalculator(string s)
{
    return substringCalculator(s,0);
}

int main(int argc, char** argv)
{   
    string s;
    s = argv[1];
    long result = substringCalculator(s);
    std::cout << "No of unique Substring - " << result << std::endl;
    return 0;
}
