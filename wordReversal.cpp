// PROBLEM DEFINITION
// ------------------
// Reverse each word in the input string.
// The order of the words will be unchanged.
// A word is made up of letters and/or numbers.
// Other characters (spaces, punctuation) will not be reversed.

// NOTES
// ------
// Write production quality code
// We prefer clarity over performance (though if you can achieve both - great!)
// You can use the language that best highlights your programming ability
// the template below is in Python – but you can write in C++ 
// A working solution is preferred (assert in main() should succeed)
// Bonus points for good tests

#include <string>
#include <assert.h>
#include <iostream>
#include <stack>

using namespace std;

std::string reverse_words(const std::string &str)
{
  std::stack<char> st; 
  std::string mRet;
  
    // Traverse given string and push all characters 
    // to stack until we see a space. 
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] != ' ' && !ispunct(str[i]))
            st.push(str[i]);
 
        else
        {
            while (st.empty() == false)
            {
                mRet.push_back(st.top());
                st.pop();
            }
            mRet.push_back(str[i]);
        }
    }

    // Since there may not be space after 
    // last word. 
    while (st.empty() == false) { 
        mRet.push_back(st.top());
        st.pop(); 
    } 
    return mRet;
}

int main()
{
    std::string test_str = "String;   2be reversed...";
    assert(reverse_words(test_str) == "gnirtS;   eb2 desrever...");
    return 0;
}