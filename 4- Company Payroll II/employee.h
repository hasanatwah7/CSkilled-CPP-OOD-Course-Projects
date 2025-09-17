#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "payable.h"
#include "invoice.h"

class employee : public Payable {
protected:
    std::vector<invoice*> invoices;

public:
    void add_invoice(invoice* inv) {
        invoices.push_back(inv);
        add_money(inv->get_money());
    }

    void print() override {
        std::cout << "Employee: " << get_name()
                  << "    salary: " << get_money() << std::endl;
    }

    bool compare(Payable* p1, Payable* p2) override {
        if (p1->get_money() == p2->get_money()) {
            return p1->get_name() < p2->get_name();
        }
        return p1->get_money() < p2->get_money();
    }

    void sort(bool cmp) override {
        std::sort(invoices.begin(), invoices.end(),
                  [this](invoice* a, invoice* b) {
                      return this->compare(a, b);
                  });
    }
};

#endif // EMPLOYEE_H
