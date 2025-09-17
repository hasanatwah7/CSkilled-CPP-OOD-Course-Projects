// usermanager.h

#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include <string>
#include "admin.h"
#include "enduser.h"
#include "book.h"

using namespace std;

class admin;
class enduser;

class usermanager {
private:
    vector<enduser> endusers;
    vector<admin> admins;
    vector<book> books;

public:
    void sign_up(string _name, string _password) {
        enduser new_user(_name, _password);
        endusers.push_back(new_user);
    }

    // Updated login to use a reference to a pointer (user*&)
    bool login(string _name, string _password, user*& _user) {
        for (size_t i = 0; i < admins.size(); i++) {
            if (_name == admins[i].get_name() && _password == admins[i].get_pass()) {
                _user = &admins[i];
                return true;
            }
        }
        for (size_t i = 0; i < endusers.size(); i++) {
            if (_name == endusers[i].get_name() && _password == endusers[i].get_pass()) {
                _user = &endusers[i];
                return true;
            }
        }
        return false;
    }

    void add_book(string book_name, int no_of_pages) {
        books.emplace_back(book_name, no_of_pages);
    }

    void add_admin(const admin& _admin) {
        admins.push_back(_admin);
    }

    // Return by reference for efficiency
    vector<book>& get_books() {
        return books;
    }
};

#endif //USERMANAGER_H