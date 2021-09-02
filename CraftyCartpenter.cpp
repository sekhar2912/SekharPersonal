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
#include <unordered_set>
#include <algorithm>
#include <iterator>

using namespace std;

class Item
{
private:
    int key;

public:
    
    Item(int x = -1)
    {
        key = x;
    }

    int getKey()
    {
        return key;
    }

    bool operator==(const Item &t) const
    {
        return (key == t.key);
    }

    bool operator<(const Item &t) const
    {
        return (key < t.key);
    }

    bool operator>(const Item &t) const
    {
        return (key > t.key);
    }
};

class Cabinet {

private:
 int _capacity;
 std::deque<Item> itemGroup{};
 
public:
    Cabinet() = default;
    Cabinet(int capacity):_capacity(capacity) {}
    std::deque<Item> getItemGroup() { return itemGroup;}
    
    Item addItem(Item newItem) 
    {
      /*
      //Adds item to a cabinet, 
      if the cabinet is full, returns the oldest item (after removing it), 
      else returns invalid item
      */
    
        int size = static_cast<int>(itemGroup.size());
        if ( size==_capacity)
        { 
            Item temp =  itemGroup.front();
            itemGroup.pop_front();
            itemGroup.push_back(newItem);
            return temp;
        }
        else if(size < _capacity)
        {
            itemGroup.push_back(newItem);
            return Item(-1);
        }
        else if (size > _capacity ) 
            throw std::exception();
        
        return Item(-1);
    }
    
};


class TheWorkshop
{

private:
    int totalCabinets;
    std::vector<Cabinet> cabinetGroup;
    std::set<Item> outsideTheShop{};
public:
    TheWorkshop(int x, std::vector<int> cabinetCapacityArray)
    {
        totalCabinets = x;
        for (int cabinetSize : cabinetCapacityArray)
        {
            Cabinet temp(cabinetSize);
            cabinetGroup.emplace_back(temp);
        }
    }
   
private:
    void addItemToShop(Item newItem, int cabinetIndex) 
    {
        if (cabinetIndex == totalCabinets)
        {
            outsideTheShop.emplace(newItem);
            return;
        }
        Item tempItem = cabinetGroup.at(cabinetIndex).addItem(newItem);
        if (tempItem.getKey() != -1)
            addItemToShop(tempItem, ++cabinetIndex);
    }
public:
    bool isElementPresentInItemGroup(std::deque<Item> visited, Item x)
    {
        auto it = find(visited.begin(), visited.end(), x);
        if(it->getKey() == x.getKey()) return true;
        
        return false;
    }
    //Checks if the given item is new or was used previously. 
    //  Returns -1 if the item is new.
    //  Returns -2 if the item was found outside the shop. Also removes it from there.
    //  Returns with the "index" value (0 to N-1) of the cabinet where item was found, also removes it from there.

    int isNewItem(Item e)
    {
        int size = cabinetGroup.size();
        for (int i = 0; i < size; i++)
        {
            auto dq = cabinetGroup.at(i).getItemGroup();
            if (isElementPresentInItemGroup(dq, e))
            {
                auto where = find(dq.begin(), dq.end(), e);
                dq.erase(where);
                return i;
            }
        }

        if (outsideTheShop.find(e) != outsideTheShop.end())
        {
            auto where = find(outsideTheShop.begin(), outsideTheShop.end(), e);
            outsideTheShop.erase(where);
            //Found Outside
            return -2;
        }
        else
        {
            //New Item
            return -1;
        }
    }

    //     //Method that is called in the main function
    //     //  1. First checks if the item is new by using isNewItem()
    //     //  2. Adds the item to the shop using addItemToShop()
    //     //  3. Depending upon the value returned by isNewItem(), returns the   appropriate string
    //     //Named "workOnAnItem", because the carpenter is currently working on the given item

    std::string workOnAnItem(Item e)
    {
        int returnValue = isNewItem(e);
        if (returnValue == -1)
        {
            addItemToShop(e, 0);
            return "NEW";
        }
        else if (returnValue == -2)
        {
            addItemToShop(e, 0);
            return "OUTSIDE";
        }
        else if (returnValue >= 0)
        {
            addItemToShop(e, 0);
            return std::to_string(returnValue + 1);
        }
        else
        {
            return "INPUT_ERROR";
        }
    }
    };


int main()
{
    
    try
    {
        std::string cabinetInfo;
        std::vector<int> cabinetCapacityArrayInt; // Input --1
        getline(cin, cabinetInfo);
        std::vector<std::string> cabinetCapacityArray{};
        if (cabinetInfo.length() > 0)
        {
            stringstream check1(cabinetInfo);      
            string intermediate;
            
            while(getline(check1, intermediate, ' '))
            {
                cabinetCapacityArray.push_back(intermediate);
            }
           
        }
        
        for (int i = 0; i < cabinetCapacityArray.size(); i++)
            {
                if (std::stoi(cabinetCapacityArray[i]) <= 0 ||
                    std::stoi  (cabinetCapacityArray[i]) >= 1024)
                    throw std::exception();
                cabinetCapacityArrayInt.push_back(
                    std::stoi(cabinetCapacityArray[i]));
            }

        int inputItemCount;
        std::cin >> inputItemCount;
        
        if ((inputItemCount <= 0) || (inputItemCount >= (long)pow(2, 32)))
            throw std::exception();

        std::vector<long> inputSequence;
        int cabinetCount = cabinetCapacityArrayInt.size(); //N

        if ((cabinetCount <= 0) || (cabinetCount >= 64))
            throw std::exception();

        TheWorkshop thisWorkshop(cabinetCount, cabinetCapacityArrayInt);

        std::string returnString = "";
        for (long i = 0; i < inputItemCount; i++)
        {
            long temp;
            cin >> temp;
            inputSequence.push_back(temp);
            //Checking the limits according to what is defined in the problem statement
            if ((temp <= 0) || (temp >= (long)pow(2, 32)))
                throw std::exception();
        }

        for (long itemID : inputSequence)
        {
            Item newItem(itemID);
            returnString = thisWorkshop.workOnAnItem(newItem);
        }

        std::cout << returnString;
    }
    catch (const std::exception &e)
    {
        std::cout << "INPUT_ERROR";
    }
    
    return 0;
}