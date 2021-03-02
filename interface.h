#pragma once
#include <iostream>
#include <string>
template<class >
class Interface {
    public:
    virtual void push(int) = 0;
    virtual bool isEmpty() = 0;
    //virtual int &operator +() =0;
};