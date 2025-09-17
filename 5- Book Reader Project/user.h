// user.h

#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "reading_session.h"

// Forward declaration to avoid circular dependencies
class usermanager;

using namespace std;

class user {
protected:
    string name;
    string password;

public:
    user(string _name, string _password) : name(_name), password(_password) {}
    user() {}
    virtual ~user() {} // Virtual destructor

    string get_name() { return name; }
    string get_pass() { return password; }

    // Pure virtual function to be implemented by derived classes
    virtual void show_menu(usermanager& manager) = 0;
};

#endif //USER_H