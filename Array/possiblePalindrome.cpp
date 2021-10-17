#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s)
{
    std::string p = s;
    std::reverse(p.begin(), p.end());
    if (s == p)
        return true;
    else
        return false;
}

vector<string> partition(string s)
{
    int len = s.size();
    vector<string> mRetStr;
    for (int i = 0; i < len; i++)
    {
        for (int j = 1; j <= len - i; j++)
        {
            if (isPalindrome(s.substr(i, j)))
                mRetStr.push_back(s.substr(i, j));
        }
    }
    return mRetStr;
}

int main()
{
    std::string input = "madam";
    vector<string> mRet = partition(input);
    for (int i = 0; i < mRet.size(); i++)
        std::cout << mRet.at(i) << std::endl;
    return 0;
}