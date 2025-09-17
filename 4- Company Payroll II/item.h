#ifndef ITEM_H
#define ITEM_H

#include <string>

class item {
protected:
    std::string name;
    int price = 0;

public:
    void set_price(int price) { this->price = price; }
    void set_name(const std::string& name) { this->name = name; }
    int get_price() const { return price; }
    std::string get_name() const { return name; }
};

#endif // ITEM_H
