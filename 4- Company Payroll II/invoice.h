#ifndef INVOICE_H
#define INVOICE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "payable.h"
#include "item.h"

class invoice : public Payable {
protected:
    std::vector<item> items;

public:
    void add_item(const item& it) {
        items.push_back(it);
        add_money(it.get_price());
    }

    void print() override {
        for (auto& it : items) {
            std::cout << it.get_name() << "    price: " << it.get_price() << std::endl;
        }
        std::cout << "Total: " << get_money() << std::endl;
    }

    bool compare(Payable* p1, Payable* p2) override {
        if (p1->get_money() == p2->get_money()) {
            return p1->get_name() < p2->get_name();
        }
        return p1->get_money() < p2->get_money();
    }

    void sort(bool cmp) override {
        std::sort(items.begin(), items.end(),
                  [cmp](const item& a, const item& b) {
                      return cmp ? a.get_price() < b.get_price()
                                 : a.get_price() > b.get_price();
                  });
    }
};

#endif // INVOICE_H
