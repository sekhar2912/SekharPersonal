/*

You are driving a vehicle that has capacity empty seats initially available for passengers.  
The vehicle only drives east (ie. it cannot turn around and drive west.)

Given a list of trips, trip[i] = [num_passengers, start_location, end_location] 
contains information about the i-th trip: the number of passengers that must be picked up,
 and the locations to pick them up and drop them off.  The locations are given as the number of 
kilometers due east from your vehicle's initial location.

Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 
Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
Example 3:

Input: trips = [[2,1,5],[3,5,7]], capacity = 3
Output: true
Example 4:

Input: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
Output: true
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

bool carPooling(vector<vector<int>> &trips, int capacity)
{
    /* 1. Maintain a array of Passenger list
    scan the trip and add the no of passenger in the array
    Do a boundary check.
    */
    int passengers[1001] = {0};
    for (auto &trip : trips)
        for (int start = trip[1]; start < trip[2]; start++)
        {
            passengers[start] += trip[0];
            if (passengers[start] > capacity)
                return false;
        }
    return true;
}

int main()
{
    vector<vector<int>> trips_1{{2, 1, 5}, {3, 3, 7}};
    int capacity = 4;
    bool retVal = carPooling(trips_1, capacity);
    std::cout << "Status - " << retVal;
    return 0;
}