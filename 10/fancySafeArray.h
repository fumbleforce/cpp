#pragma once
#include "safeArray.h"
#include <iostream>

template<typename T>
class FancySafeArray: public SafeArray<T>
{

public:
    FancySafeArray() : SafeArray<T>() {}


    FancySafeArray operator+=(const FancySafeArray &rhs)
    {
        int i;
        int newSize = this->size() + rhs.size();
        T * newList = new T[newSize];

        for (i = 0; i < this->size(); i++)
        {
            newList[i] = this->get(i);
        }
        for (i = this->size(); i < rhs.size(); i++)
        {
            newList[i] = rhs[i];
        }
        delete[] this->data;
        this->data = newList;
        this->currentSize = newSize;

        return *this;
    }

    FancySafeArray operator+(const FancySafeArray &rhs)
    {
        FancySafeArray m = *this;
        m += rhs;
        return m;
    }

    std::ostream& operator<<(std::ostream& os)
    {
        os << "[";
        for (int j = 0; j < this->size(); j++)
        {
            os << " " << this->data[j] << " ";
        }
        os << "]" << std::endl;

        return os;
    }


private:


};