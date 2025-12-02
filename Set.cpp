#include "Set.h"

Set::Set() 
{
    data = nullptr;
    size = 0;
}

Set::~Set() 
{
    delete[] data;
}

Set::Set(const Set& other) //copy constructor
{
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

Set& Set::operator=(const Set& other) 
{
    if (this == &other) return *this;

    delete[] data;
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }

    return *this;
}

bool Set::exists(int value) const // prevent dups
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == value)
        {
            return true;
        }
    }
    return false;
}

Set& Set::operator+=(int value) 
{
    if (exists(value)) return *this; // if value present ignore 

    int* temp = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = data[i];
    }

    temp[size] = value; // append 
    size++;

    delete[] data;
    data = temp;

    return *this;
}

Set& Set::operator-=(int value) 
{
    if (!exists(value)) return *this; // if value present remove it

    int* temp = new int[size - 1];
    int idx = 0;

    for (int i = 0; i < size; i++)
    {
        if (data[i] != value)
        {
            temp[idx++] = data[i];
        }
    }
    size--;
    delete[] data;
    data = temp;

    return *this;
}

Set operator*(const Set& a, const Set& b) 
{
    Set result;
    for (int i = 0; i < a.size; i++) // intersection gets all elements from a and check whuch ones are also in b
    {
        if (b.exists(a.data[i]))
        {
            result += a.data[i];
        }
    }
    return result;
}

Set operator+(const Set& a, const Set& b) 
{
    Set result;
    for (int i = 0; i < a.size; i++) // Union adds all elements from a and b
    {
        result += a.data[i];
    }
    for (int i = 0; i < b.size; i++)
    {
        result += b.data[i];
    }
    return result;
}

Set operator-(const Set& a, const Set& b) 
{
    Set result;
    for (int i = 0; i < a.size; i++) // Returns elements that are in a but not in b. 
                                     // For each element of a, if b does not contain it, add it to result.
    {
        if (!b.exists(a.data[i]))
        {
            result += a.data[i];
        }
    }
    return result;
}

void Set::print() const 
{
    std::cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "}" << std::endl;
}
