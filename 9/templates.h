#pragma once
#include <iostream>
#include <string>

template<typename T>
class SimpleSet
{
    public:
        /** Construct empty set **/
        SimpleSet()
        {
            this->data = new T[0];
            maxSize = 0;
            currentSize = 0;
        }
        /** Insert i into set, return true if the element was inserted, else false **/
        bool insert(T i)
        {
            if (!exists(i))
            {
                if (currentSize == maxSize)
                {
                    resize(maxSize + 10);
                }

                data[currentSize] = i;
                currentSize++;

                return true;
            }
            else
            {
                return false;
            }
        }
        /** Returns true if i is in the set **/
        bool exists(T i)
        {
            return find(i) >= 0;
        }
        /** Removes i from the set, return true if an element was removed **/
        bool remove(T i)
        {
            int index = find(i);
            if (index >= 0)
            {
                for (int j = index; j < currentSize-1; j++)
                    data[j] = data[j+1];

                currentSize--;
                return true;
            }
            else
            {
                return false;
            }
        }
    private:
        /** Dynamic array containing set elements **/
        T *data;
        /** Current number of elements **/
        int currentSize;
        /** Max capasity of data **/
        int maxSize;
        /** Returns the index where i may be found, else an invalid index. **/
        int find(T i)
        {
            for (int j = 0; j < currentSize; j++)
            {
                if (data[j] == i)
                    return j;
            }
            return -1;
        }
        /** Resizes data, superflous elements are dropped. **/
        void resize(int n)
        {
            T* dataRezised = new T[n];
            for (int i = 0; i < currentSize; i++)
                dataRezised[i] = data[i];
            maxSize = n;
            delete[] this->data;
            data = dataRezised;
        }
};










class Person
{
private:
    std::string firstName;
    std::string lastName;


public:
    Person();
    Person(std::string first, std::string last);
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getFullName() const { return firstName + " " + lastName; }
};