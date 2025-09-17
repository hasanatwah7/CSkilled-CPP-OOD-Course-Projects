cmake_minimum_required(VERSION 3.31)
project(Company_Payroll_II)

set(CMAKE_CXX_STANDARD 26)

add_executable(Company_Payroll_II main.cpp
        employee.h
        payable.h
        invoice.h
        interface.h
        payroll.h
        item.h
        )
