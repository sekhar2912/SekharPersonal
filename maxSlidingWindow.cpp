/*
You are given an array of integers nums, there is a sliding window of size k 
which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding window
moves right by one position.

Return the max sliding window.
 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/

#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

/*
Here use of set is important as the elements are stored in sorted order and we have easy 
way to find the max element
*/
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    std::vector<int> retVec;
    std::multiset<int> tempSet;
    if (nums.empty())
        return retVec;
    if (nums.size() == 1)
        return nums;

    for (int j = 0; j < nums.size(); j++)
    {
        tempSet.emplace(nums.at(j));
        if (j >= k)
            tempSet.erase(tempSet.find(nums.at(j - k)));
        if (j >= k - 1)
            retVec.emplace_back(*tempSet.rbegin());
    }
    return retVec;
}
int main()
{
    std::vector<int> inputVec{1, 3, -1, -3, 5, 3, 6, 7};
    int k{3};
    std::vector<int> retVec = maxSlidingWindow(inputVec, 1);
    for (auto &ele : retVec)
        std::cout << ele << "\n"
                  << std::endl;
    return 0;
}