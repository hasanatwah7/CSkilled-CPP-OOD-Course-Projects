// book.h

#ifndef BOOK_H
#define BOOK_H
#include <string>

using namespace std;
class book {
protected:
    string name;
    int no_of_pages;
public:
    book(string name, int no_of_pages) : name(name), no_of_pages(no_of_pages) {}
    book() : name(""), no_of_pages(0) {}

    void set_name(string _name) {
        name = _name;
    }
    void set_no_of_pages(int num_pages) {
        this->no_of_pages = num_pages;
    }
    string get_name() const { // Added const for read-only access
        return name;
    }
    int get_no_of_pages() const { // Added const for read-only access
        return no_of_pages;
    }
};

#endif //BOOK_H