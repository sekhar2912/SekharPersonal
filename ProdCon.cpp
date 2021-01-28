// # Command to build 
// g++ ProdCon.cpp -o prodcon -pthread -std=c++14

#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <condition_variable>

using namespace std;

std::mutex my_mutex;
std::condition_variable cond;
deque<int> buffer;
const unsigned int buffer_size = 50;

void producer(int val)
{
    while(val--)
    {
        std::unique_lock<std::mutex>locker(my_mutex);
        cond.wait(locker,[](){return buffer.size()<buffer_size;});
        buffer.push_back(val);
        std::cout << "Producer - produced" << val <<std::endl;
        locker.unlock();
        cond.notify_one();
    }
}

void consumer()
{
    while(true)
    {
        std::unique_lock<std::mutex>locker(my_mutex);
        cond.wait(locker,[](){return buffer.size()>0;});
        int val = buffer.back();
        std::cout << "consumer - consumed" << val <<std::endl;
        locker.unlock();
        cond.notify_one();
    }
}

int main()
{
    std::thread t1(producer,100);
    std::thread t2(consumer);

     t1.join();
     t2.join();
}