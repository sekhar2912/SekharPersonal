#include <iostream>
#include <memory>
#include <cassert>

using namespace std;

void unique_demo()
{
    std::unique_ptr<int> up{std::make_unique<int>(10)};
    std::cout << "About to release ..\n";
    int* fp = up.release();
    std::cout << "Value "<<*fp;
    assert (up.get() == nullptr);
    assert (up == nullptr);
    delete fp;
 
    std::cout << "Foo is no longer owned by unique_ptr...\n";
    up.reset(new int{100}); 
    int *s = up.get();
    std::cout<< "New Val :- "<<*s;


 
    
    
}

void shared_demo()
{
  int *p = new int(10);
  std::shared_ptr<int> sp = make_shared<int> (12);
  std::cout << *sp;
}

void weak_demo()
{
    int *p = new int(10);
    std::shared_ptr<int> sp = make_shared<int> (12);
    std::weak_ptr<int> wp = sp;
    std::cout << "use_count == " << sp.use_count() << ": ";
    std::cout << "use_count == " << wp.use_count() << ": ";

    if (auto spt = wp.lock()) { // Has to be copied into a shared_ptr before usage
	std::cout << *spt << "\n";
    }
    else {
        std::cout << "wp is expired\n";
    }

}

int main()
{
    unique_demo();
    return 0;
}
