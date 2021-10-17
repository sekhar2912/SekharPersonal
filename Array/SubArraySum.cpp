#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


    vector<int> subarraySum(int arr[], int &n, int &s)
    {
       int actual_sum{0};
       int begin{0};
       std::vector<int> mRetVal;
       while(actual_sum < s)
       {
           for(int i =begin;i<n;i++)
           {
               
               actual_sum =actual_sum + arr[i];
               if(actual_sum == s)
               {
                    mRetVal.push_back(begin+1);
                    mRetVal.push_back(i+1);
                    return mRetVal;
                    
               }
               else if(actual_sum > s)
               {
                   begin = begin +1;
                   actual_sum = 0;
                   break;
               }      
           }
           
      }
       return mRetVal;
    }



int main()
{
int N = 5, S = 12;
int A[] = {1,2,3,7,5};
auto mRet = subarraySum(A,N,S);
std::cout << "Output " << mRet[0] << " " <<  mRet[1] << std::endl;
    return 0;
}