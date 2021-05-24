/*

Given n non-negative integers representing an elevation map where the width of each bar is 1,
 compute how much water it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is 
represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

int trap(vector<int> &height)
{
    int len = height.size();
    int area{0};
    if (len == 0)
        return 0;
    std::vector<int> left_max(len);
    std::vector<int> right_max(len);
    // Get the left Max - Precomputed readings
    left_max[0] = height[0];
    for (int i = 1; i < len; i++)
        left_max[i] = max(height[i], left_max[i - 1]);
    right_max[len - 1] = height[len - 1];
    for (int i = len - 2; i >= 0; i--)
        right_max[i] = max(height[i], right_max[i + 1]);
    for (int i = 0; i < len; i++)

        area += min(right_max[i], left_max[i]) - height[i];
    return area;
}

int main()
{

    std::vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << "Max Water Trapped - " << trap(height) << std::endl;
    return 0;
}