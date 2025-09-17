//
// Created by Hasan Atwah on 8/29/2025.
//

#ifndef INVOICE_H
#define INVOICE_H

#include <iostream>
#include <string>
#include <vector>

#include "item.h"

using namespace std;
class invoice {
private:
    vector<item> items;
    int total = 0;
    int date;
public:
    void add_item(item item) {
        items.push_back(item);
        total += item.getPrice();
    }
    int get_invoice_total() {
        return total;
    }
    void set_date(int _date) {
        date = _date;
    }
    int get_date() { return date; }
    bool check_on_date(int _date) {
        return this->date > _date;
    }
};

#endif //INVOICE_H
