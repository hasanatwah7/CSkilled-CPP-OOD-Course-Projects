#ifndef PAYABLE_H
#define PAYABLE_H

#include <string>
#include "interface.h"

class Payable : public Interface {
protected:
    int money = 0;
    std::string name;
public:

    void print() override {} // default empty

    bool compare(Payable* p1, Payable* p2) override { return false; }

    void sort(bool cmp) override {}

    void set_money(int money) { this->money = money; }
    void add_money(int money) { this->money += money; }
    void set_name(const std::string& name) { this->name = name; }
    int get_money() const { return money; }
    std::string get_name() const { return name; }
};

#endif // PAYABLE_H
