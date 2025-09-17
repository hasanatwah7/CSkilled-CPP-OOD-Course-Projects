cmake_minimum_required(VERSION 3.31)
project(Book_Reader_Project)

set(CMAKE_CXX_STANDARD 23)

add_executable(Book_Reader_Project main.cpp
        user.h
        admin.h
        enduser.h
        usermanager.h
        reading_session.h
        book.h)
