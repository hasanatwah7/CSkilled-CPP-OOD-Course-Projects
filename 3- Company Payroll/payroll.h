//
// Created by Hasan Atwah on 8/29/2025.
//

#ifndef PAYROLL_H
#define PAYROLL_H

#include <iostream>
#include <string>
#include <vector>
#include "employees.h"

class payroll {
private:
        vector<employee*> employees;
public:
        void add_employee(employee &employee) {
                employees.push_back(&employee);
        }
        void print()
        {
                for (int i = 0; i < employees.size(); ++i)
                {
                        std::cout << employees[i]->get_name() << ' ' <<  employees[i]->payroll() << endl;
                }
        }
};

#endif //PAYROLL_H
