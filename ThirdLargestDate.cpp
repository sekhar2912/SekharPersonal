#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Date
{
    int Day;
    int Year;
    int Month;
};

/*
 * Complete the function below.
 */

bool operator<(const Date& date1, const Date& date2)
{
        if(date1.Year<date2.Year)
                return true;
        if(date1.Year== date2.Year and date1.Month<date2.Month)
                return true;
        if(date1.Year== date2.Year and date1.Month==date2.Month and date1.Day<date2.Day)
                return true;
        return false;
}

Date ThirdLatest(std::vector<Date> & dates) { 
        std::set<Date>Unique_Dates;
        
        for(auto i:dates)
        {
            Unique_Dates.insert(i);
        }
        //clear original dates vector
        dates.clear();
        //push dates from the set back into dates vector
        for(auto &i: Unique_Dates)
        {
               dates.push_back(i);
        }
        int DatesSize=dates.size();
        return dates.at(DatesSize-3);
}

int main() {
    int numberOfEntries;
    int res = scanf("%d\n", &numberOfEntries);
    std::vector<Date> dates;
    for (int i = 0; i < numberOfEntries; ++i)
    {
        Date date;
        res = scanf("%d-%d-%d", &date.Day, &date.Month, &date.Year);
        dates.push_back(date);
    }    
    
    ThirdLatest(dates);
    Date result = ThirdLatest(dates);
    printf("%02d-%02d-%d\n", result.Day, result.Month, result.Year);
    return 0;
}