#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Vector 
{
private:
    T* arr_;
    int size_{};
    int volume_{};

public:

    Vector(int N) 
    {
        arr_ = new T[N];
        volume_ = N;
        size_ = N;
    }
    ~Vector() 
    {
        delete[] arr_;
    }
    ///////////////////////////////////////////////////
    void AddMemory()
    {
        volume_ += 1;
        T* tmp = arr_;
        arr_ = new T[volume_];
        for (int i = 0; i < size_; ++i)
        {
            arr_[i] = tmp[i];
        }
        delete[] tmp;
    }

    void push_back(T value) 
    {
        AddMemory();
        arr_[size_++] = value;
    }
    void Delete(int index) 
    {
        for (int i = index + 1; i < size_; ++i)
        {
            arr_[i - 1] = arr_[i];
        }
        --size_;
    }
    void pop_back()
    {
        for (int i = size_ + 1; i < size_-1; ++i)
        {
            arr_[i - 1] = arr_[i];
        }
        --size_;
    }
    ///////////////////////////////////////////////////
    T begin() 
    {
        return arr_[0];
    }
    T end() 
    {
        return arr_[size_];
    }
    ///////////////////////////////////////////////////
    T& operator[](size_t index) 
    {
        return arr_[index];
    }
    template<typename T>
    friend ostream& operator<<(std::ostream& cout, Vector<T>& v1);
};

template<typename T>
ostream& operator <<(ostream& out, Vector<T>& mas)
{
    out << endl;
    for (size_t i = 0; i < mas.size_; i++)
    {
        out << mas[i] << "  ";
    }
    out << endl;
    return out;
}
