#ifndef PAYROLL_H
#define PAYROLL_H

#include <vector>
#include <algorithm>
#include "payable.h"

class payroll {
private:
    std::vector<Payable*> payables;

    bool cmp(Payable* p1, Payable* p2) {
        return p1->get_money() < p2->get_money();
    }

public:
    payroll() {}

    void add_payable(Payable* p) {
        payables.push_back(p);
    }

    void print() {
        for (auto* p : payables) {
            p->print();
        }
    }

    void sort_payables() {
        std::sort(payables.begin(), payables.end(),
                  [this](Payable* a, Payable* b) {
                      return this->cmp(a, b);
                  });
    }
};

#endif // PAYROLL_H
