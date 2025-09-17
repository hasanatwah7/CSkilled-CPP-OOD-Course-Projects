//
// Created by Hasan Atwah on 8/29/2025.
//

#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "invoice.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
class employee
{
protected:
    string name;

public:
    employee() { }
    employee(string _name) : name(_name)
    {

    }
    string get_name() {
        return name;
    }
    void set_name(string _name) {
        name = _name;
    }
    virtual double payroll()
    {
        throw logic_error("not implemented , do override \n employee class") ;
        return -1 ;
    }
};
class salaried_employee : public employee
{
protected:
    int salary;
    double percentage;
    invoice inv;
public:
    salaried_employee(string _name, int _salary, int _percentage, invoice _inv) : employee(_name) , salary(_salary), percentage(_percentage), inv(_inv) { }
    double payroll() override {
        return salary + (percentage/100) * inv.get_invoice_total();
    }
    void set_salary(int _salary) {
        salary = _salary;
    }
    void set_percentage(int _percentage) {
        percentage = _percentage;
    }
    int get_salary() {
        return salary;
    }
    double get_percentage() {
        return percentage;
    }
    void set_invoice(invoice _invoice) {
        inv = _invoice;
    }
};

class hourly_employee : public employee {
protected:
    int hours;
    int LEperhour;
public:
    hourly_employee(string _name, int _hours, int _LEperhour) : employee(_name) , hours(_hours), LEperhour(_LEperhour) { }
    hourly_employee() { }
    double payroll() {
        throw logic_error("Labourer Or Sales??, do Override\n hourly employee");
        return -1;
    }
    void set_hourly(int _hours) { hours = _hours; }
    int get_hourly() { return hours; }
    void set_LEperhout(int _LEperhout) { LEperhour = _LEperhout; }
    int get_LEperhout() { return LEperhour; }
};

class labourer : public hourly_employee {
public:
    labourer(string _name, int _hours, int _LEperhours) : hourly_employee(_name, _hours, _LEperhours) { }
    labourer() { }
    double payroll() {
        return hours * LEperhour;
        // hours = 0;
    }
};

class sales_hourly : public hourly_employee {
public:
    sales_hourly(string _name, int _hours, int _LEperhours) : hourly_employee(_name, _hours, _LEperhours) { }
    sales_hourly() { }
    double payroll() {
        return hours * LEperhour;
        // hours = 0;
    }
};

#endif //EMPLOYEES_H
