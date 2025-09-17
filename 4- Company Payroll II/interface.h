#ifndef INTERFACE_H
#define INTERFACE_H

class Payable; // Forward declaration

class Interface {
public:
    virtual void print() = 0;
    virtual bool compare(Payable* p1, Payable* p2) = 0;
    virtual void sort(bool cmp) = 0;

    virtual ~Interface() {}
};

#endif // INTERFACE_H
