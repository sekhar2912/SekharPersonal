#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>

/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. 
Otherwise, add the key-value pair to the cache. If the number of keys exceeds 
the capacity from this operation, evict the least recently used key.
*/
using namespace std;

class LRUCache {
private:
 int _capacity;
 std::list<int>_keys;
 std::unordered_map<int,pair<int,list<int>::iterator>>_map;
public:
    
    LRUCache(int capacity):_capacity(capacity) {}
    void printList()
    {
         // Print out the list
    std::cout << "l = { "; 
    for (int n : _keys) {
        std::cout <<  n<< ", ";
       
    }
    std::cout << "};\n";
    }
    int get(int key) {
        if(_map.find(key) != _map.end())
        {
            _keys.erase(_map[key].second);
            _keys.push_front(key);
            _map[key].second = _keys.begin();
            return _map[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
       if(_map.find(key) != _map.end())
       {
           _keys.erase(_map[key].second);
           _keys.push_front(key);
           _map[key] = {value,_keys.begin()};
       }
       else
       {
           if(_keys.size() >=_capacity)
           {
               _map.erase(_keys.back());
               _keys.pop_back();
           }
           _keys.push_front(key);
           _map[key] = {value,_keys.begin()};
       }
       
    }
};

// int main()
// {
//     LRUCache *obj = new LRUCache(5);
//     //int param_1 = obj->get(1);
//     obj->put(1, 1);
//     obj->put(2, 3);
//     obj->put(3, 4);
//     obj->put(4, 7);
//     obj->put(6, 10);
//     obj->printList();
//     std::cout << "-------------------------" << std::endl;
//     obj->get(1);
//     obj->printList();
//     std::cout << "-------------------------" << std::endl;
//     obj->get(3);
//     obj->printList();
//     std::cout << "-------------------------" << std::endl;
//     obj->put(1, 5);
//     obj->printList();
//     std::cout << "-------------------------" << std::endl;
//     obj->put(12, 7);
//     obj->printList();
//     std::cout << "-------------------------" << std::endl;
//     obj->put(5, 2);
//     obj->printList();
//     return 0;
// }

int main()
{
    LRUCache *obj = new LRUCache(2);
    //int param_1 = obj->get(1);
    obj->put(2, 2);
    obj->put(1, 1);
    obj->printList();
    std::cout << "-------------------------" << std::endl;
    obj->get(2);
    obj->printList();
    std::cout << "-------------------------" << std::endl;
    obj->get(1);
    obj->printList();
    std::cout << "-------------------------" << std::endl;
    obj->get(2);
    obj->printList();
    std::cout << "-------------------------" << std::endl;
    obj->put(3, 3);
    obj->printList();
    std::cout << "-------------------------" << std::endl;
    obj->put(4, 4);
    obj->printList();
    std::cout << "-------------------------" << std::endl;

    obj->get(3);
    obj->printList();
    std::cout << "-------------------------" << std::endl;
    obj->get(2);
    obj->printList();
    std::cout << "-------------------------" << std::endl;
    obj->get(1);
    obj->printList();
    std::cout << "-------------------------" << std::endl;
    obj->get(4);
    obj->printList();




    return 0;
}