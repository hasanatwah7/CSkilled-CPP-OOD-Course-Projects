#include <bits/stdc++.h>
#include "employee.h"
#include "interface.h"
#include "invoice.h"
#include "item.h"
#include "payable.h"
#include "payroll.h"

using namespace std;

int main() {
    payroll payroll;
    Payable* hasan = new employee();
    hasan->set_name("Hasan");
    hasan->set_money(5000);
    payroll.add_payable(hasan);
    Payable* hanin = new employee();
    hanin->set_name("Hanin");
    hanin->set_money(7000);
    payroll.add_payable(hanin);
    Payable* mostafa = new employee();
    mostafa->set_name("Mostafa");
    mostafa->set_money(10000);
    payroll.add_payable(mostafa);

    payroll.sort_payables();
    payroll.print();
    return 0;
}