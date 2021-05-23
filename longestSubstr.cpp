#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

/*
Algorithm ( sliding window protocol)
1. If the leangth of the input string is 0 . SHUT....
2. Have two pointer , start_pointer and end_pointer and both point to 1st element of the string
3. Have a hashset  and scan the string from begaining
4. start_pointers set to 0 and move the end_pointers till we get the last element of the string
    a) if the element[end_pointers] is not in hashset, insert it
       calculate the max_lenth
       else
          if we encounter an element already present in hashset, then remove the element from hashset till 
           the element is not removed by using start_pointer

           increment the start_pointers



*/
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string& s);
};

int Solution::lengthOfLongestSubstring(string& s)
{
    
    std::unordered_set<char> containers;
    int len{static_cast<int>(s.size())};
    if (len == 0)
        return 0;
    int start_ptr{0}, end_ptr{0};
    int max_n{0};
    while (end_ptr < len)
    {
        if (!(containers.find(s[end_ptr]) != containers.end()))
        {
            containers.insert(s[end_ptr]);
            end_ptr++;
            max_n = std::max(max_n,static_cast<int>(containers.size()));
        }
        else
        {  
            // Keeping end_ptr fixed ( at the point where duplicate is received)
            // Move the start_pointer and erase the hash container till we get the duplicate element
            // Delete duplicate element from container
            containers.erase(s[start_ptr]);
            start_ptr++;
        }
    }  
    return max_n;
}

int main()
{

    std::string s {"abcdccc"};
    Solution obj;
    int ret = obj.lengthOfLongestSubstring(s);
    std::cout << "Max len " << ret;
    return 0;
}