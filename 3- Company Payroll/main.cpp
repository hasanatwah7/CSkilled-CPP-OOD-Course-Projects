#include <bits/stdc++.h>
#include "item.h"
#include "employees.h"
#include "invoice.h"
#include "payroll.h"
#define ll long long int

using namespace std;

int main()
{
    item chpsi_Haidy("Haidy", 5, "Metrbia Bgd");
    item VCola("VCola", 15, "free palastine");
    invoice inv;
    inv.add_item(chpsi_Haidy);
    inv.add_item(VCola);
    employee *hanin = new salaried_employee("hanin", 3000, 15, inv);
    employee *hasan = new sales_hourly("hasan", 3, 150);
    payroll pay1;
    pay1.add_employee(*hanin);
    pay1.add_employee(*hasan);
    pay1.print();
}