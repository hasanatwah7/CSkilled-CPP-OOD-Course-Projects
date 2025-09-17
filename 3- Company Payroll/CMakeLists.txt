cmake_minimum_required(VERSION 3.31)
project(companypayroll)

set(CMAKE_CXX_STANDARD 23)

add_executable(companypayroll main.cpp
        employees.h
        item.h
        invoice.h
        payroll.h)
