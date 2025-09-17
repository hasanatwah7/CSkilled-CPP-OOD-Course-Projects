//
// Created by Hasan Atwah on 8/29/2025.
//

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class item {
private:
    string name;
    int price;
    string details;
public:
    item(string _name, int _price, string _details) : name(_name), price(_price), details(_details) { }
    item() {}
    void setDetails(string _details) {
        details = _details;
    }
    void setName(string _name) {
        name = _name;
    }
    void setPrice(int _price) {
        price = _price;
    }
    string getName() {
        return name;
    }
    int getPrice() {
        return price;
    }
    string getDetails() {
        return details;
    }

};

#endif //ITEM_H
