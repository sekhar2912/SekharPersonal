#include <iostream>
#include <string>

using namespace std;
string getlongestPalindrome(std::string &s)
{
    int len = s.size();
    if (len == 0)
        return "";
    if (len == 1)
        return s;

    int maxlength{1};
    int center{1}, left_ptr{0}, rt_ptr{0};
    int repCharCounter = 0;
    for (int i = 1; i < len; i++)
    {
        left_ptr = i - 1;
        rt_ptr = i + 1;

        if (s[i] == s[i + 1])
        {
            rt_ptr = rt_ptr + 1;
            repCharCounter++;
        }
        while (left_ptr >= 0 && rt_ptr < len - 1)
        {

            if (s[left_ptr] == s[rt_ptr])
            {
                if (left_ptr < 0 || rt_ptr >= len - 1)
                    break;
                if (left_ptr > 0)
                    left_ptr--;
                if (rt_ptr < len - 1)
                    rt_ptr++;
            }
            else
            {
                break;
            }
        }

        if (left_ptr >= 0 && rt_ptr - left_ptr - 1 > maxlength)
        {
            maxlength = rt_ptr - left_ptr - 1;
            center = i;
        }
    }
    int start_posn{0}, end_posn{0}, no_of_element_both_side{0};
   
    no_of_element_both_side = (maxlength >repCharCounter) ? (maxlength - repCharCounter) / 2 :0;
    start_posn = center - no_of_element_both_side;
    auto str2 = s.substr(start_posn, start_posn + maxlength - 1);

    return str2;
}

int main()
{
    // std::string s{"eabbad"};
    //std::string s{"baabaa"};
    std::string s{"bb"};
    ///std::string s{"aracecard"};

    getlongestPalindrome(s);

    return 0;
}
