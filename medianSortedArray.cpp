#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>


using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums1.empty() && nums2.empty())
            return 0;

        std::vector<int> temp(nums1.size() + nums2.size());
        temp = nums1;
        temp.insert(temp.end(), nums2.begin(), nums2.end());
        std::sort(temp.begin(), temp.end());
        int n = temp.size();
        if (n % 2 == 0)
        {
            int z = n / 2;
            int e = temp[z];
            int q = temp[z - 1];
            int ans = (e + q) / 2;
            return ans;
        }

        // If length if array is odd
        else
        {
            int z = round(n / 2);
            return temp[z];
        }
    }
};

int main()
{
    std::vector<int> nums1{1,3};
    std::vector<int> nums2{2,4};
    Solution sobj;
    std::cout << "Median -- " << sobj.findMedianSortedArrays(nums1,nums2) <<std::endl;

    return 0;
}