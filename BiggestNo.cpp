
/*

Get the biggest number “n” in an array that occurs “n” times

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

int mostFrequent(vector<int> &A, int n)
{
    sort(A.begin(), A.end());
    int max_count = 1, res = A[0], curr_count = 1;
    for (int i = 1; i < n; i++)
    {
        if (A[i] == A[i - 1])
            curr_count++;
        else
        {
            if (curr_count > max_count)
            {
                max_count = curr_count;
                res = A[i - 1];
            }
            curr_count = 1;
        }
    }

    if (curr_count > max_count)
    {
        max_count = curr_count;
        res = A[n - 1];
    }

    return res;
}

int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    int k = mostFrequent(A, n);

    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[A[i]]++;
    }
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (m[A[i]] == k && max == INT_MIN)
        {
            max = A[i];
        }
        else if (m[A[i]] == k && max < A[i])
        {

            max = A[i];
        }
    }
  if (k != max ) return 0;
    if (max == INT_MIN)

        return 0;

    else

        return max;
}

int main()
{
    std::cout << "Get the biggest number “n” in an array that occurs “n” times" << std::endl;
    std::vector<int> A{3,1,4,1,5};
    //{5, 5, 5, 5, 5};
    //{3,1,4,1,5};
    //{7,1,2,8,2};
    //{3, 8, 2, 3, 4, 2};
    auto i = solution(A);
    std::cout << "The no is " << i << std::endl;
    return 0;
}