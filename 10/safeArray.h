#pragma once
#include <exception>
#include <stdexcept>
#include <iostream>

template<typename T>
class SafeArray
{
public:
    SafeArray()
    {
        this->data = new T[0];
        this->currentSize = 0;
    }
    SafeArray(int n)
    {
        this->data = new T[n];
        this->currentSize = n;
    }
    SafeArray(const SafeArray & other )
    {
        
        this->data = new T[other.size()]();
        int i;

        for (i = 0; i < other.size(); i++)
        {
            this->data[i] = other.get(i);
        }

        this->currentSize = other.size();
    }
    ~SafeArray()
    {
        delete[] this->data;
    }

    T get(int idx) const { return this->data[idx]; }
    void set(int idx, T val) { this->data[idx] = val; }
    int size() const { return this->currentSize; }

    void resize(int n) 
    {
        if (this->currentSize == n)
            return;

        if (n < 0)
            throw std::out_of_range("size is negative");
        
        int i, iterTo;

        if (n > currentSize)
            iterTo = currentSize;
        else
            iterTo = n;

        T* dataRezised = new T[n]();

        // Old data
        for (i = 0; i < iterTo; i++)
            dataRezised[i] = get(i);
        delete[] this->data;
        this->data = dataRezised;
        this->currentSize = n;
    }

    T & operator[](const int &index )
    {
        if (index >= this->size())
            throw std::out_of_range("Cannot get index");

        return this->data[index];
    }

    SafeArray<T> &operator=(const SafeArray other )
    {
        T* newdata = new T[other.size()]();
        int i;

        for (i = 0; i < other.size(); i++)
        {
            newdata.set(i, other.get(i));
        }
        delete[] this->data;

        this->data = newdata;
        this->currentSize = other.size();

        return *this;
    }

private:
    T * data;
    int currentSize;
};

