#include<iostream>
#include <vector>
/*
Given n non-negative integers a1, a2, ..., an , 
where each represents a point at coordinate (i, ai).
 n vertical lines are drawn such that the two endpoints 
 of the line i is at (i, ai) and (i, 0). Find two lines, which,
  together with the x-axis forms a container, such that the 
  container contains the most water.
*/

using namespace std;



int maxArea(vector<int>& height) {
        
        int cnt{0};
        int len = height.size();
        int min_height = height.at(0);
        int max_height = height[len-1];
        
        int min_idx{0},max_idx{len-1};
        
        // Area comparison method ( from Left to Right)    
        while(min_idx<=max_idx){
            if(height[min_idx]<height[max_idx]){
                cnt = max(cnt, (max_idx-min_idx)*height[min_idx]);
                min_idx++;
            }
            else{
                cnt = max(cnt, (max_idx-min_idx)*height[max_idx]);
                max_idx--;
            }
        }
        return cnt;
    };


int main()
{
    std::vector<int> height{1,8,6,2,5,4,8,3,7};
    std::cout << "Max Water - " << maxArea(height) << std::endl;
}
