#include <iostream>
using namespace std;
using l = long long; 

template <typename T>
class VectIterator
{

private:
    T *ptr;

public:
    explicit VectIterator()
        : ptr(nullptr)
    {
    }
    explicit VectIterator(T *p)
        : ptr(p)
    {
    }

    bool operator=(const VectIterator& rhs) const
    {
        return ptr == rhs.ptr;
    }

    bool operator!=(const VectIterator& rhs) const
    {
        return !(ptr == rhs.ptr);
    }

    T operator*() const
    {
        return *ptr;
    }

    VectIterator& operator++() 
    { 
        ++ptr; 
        return *this; 
    } 
    VectIterator operator++(int) 
    { 
        VectIterator temp(*this); 
        ++*this; 
        return temp; 
    } 
};


template <typename T>
class custVector
{

private:
    T *cust_array;
    l capacity;
    l len;

public:
    explicit custVector() =default;
    explicit custVector(l n) : capacity(n), len(0), cust_array(new T[n]) {}
    void push_back(T data);
    T pop_back();
    l size() const;
    T &operator[](l index);

    // Begin iterator 
    VectIterator<T> begin() const { return VectIterator<T>(cust_array); }
  
    // End iterator 
    VectIterator<T> end() const { return VectIterator<T>(cust_array + len); }
};



template<typename T> void custVector<T>:: push_back(T data)
{
    if (capacity == len)
    {
        // need to deallocate and reallocate
        T * temp = cust_array;
        capacity = capacity * 2;
        cust_array = new T [capacity];
        std::copy(temp,temp + len,cust_array);
    }
    cust_array[len++ ] = data;

}

template<typename T> T custVector<T>::pop_back()
{
    return cust_array[len-- -1];
}

template<typename T> l custVector<T>::size() const
{
   return len;
}
template<typename T> T& custVector<T>::operator[](l index)
{
    if(index >= len) exit(0);
    return *(cust_array + index);
}

template <typename V> 
void display_vector(V& v) 
{ 
    // Declare iterator 
    typename VectIterator ptr; 
    for (ptr = v.begin(); ptr != v.end(); ptr++) { 
        cout << *ptr << ' '; 
    } 
    cout << '\n'; 
} 

int main()
{

    cout << "For Integer data_type" << endl; 
  
    custVector<int> v; 
    v.push_back(5); 
    v.push_back(6); 
    v.push_back(7); 
    v.push_back(8); 
    v.push_back(9); 
    v.push_back(10); 
    v.push_back(11); 
    v.push_back(12); 
  
    display_vector(v);
    return 0;
}