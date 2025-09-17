// main.cpp

#include <iostream>
#include <string>
#include <vector>

#include "usermanager.h"
#include "user.h" // user must be included before admin and enduser
#include "admin.h"
#include "enduser.h"

using namespace std;

int main() {
    usermanager manager;

    // Add initial data
    manager.add_admin(admin("hanin", "123"));
    manager.add_admin(admin("hasan", "456"));
    manager.sign_up("mostafa", "789");
    manager.add_book("CPP How To Program", 10);
    manager.add_book("Clean Code", 5);

    cout << "*************************************\n";
    cout << "*********** W E L C O M E ***********\n";
    cout << "*************************************\n\n";

    int choice;
    while (true) {
        cout << "\n\n--- Main Menu ---\n";
        cout << "1: Sign-up\n";
        cout << "2: Login\n";
        cout << "0: Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nEnter a username: ";
            string username;
            cin >> username;
            cout << "Enter a password: ";
            string password;
            cin >> password;
            manager.sign_up(username, password);
            cout << "Signup successful! Please login.\n";
        } else if (choice == 2) {
            cout << "\nEnter username: ";
            string username;
            cin >> username;
            cout << "Enter password: ";
            string password;
            cin >> password;

            user* current_user = nullptr;
            if (manager.login(username, password, current_user)) {
                cout << "\nWelcome, " << current_user->get_name() << "!";
                // Polymorphic call: the correct show_menu is called automatically
                current_user->show_menu(manager);
            } else {
                cout << "\nLogin failed. Incorrect username or password." << endl;
            }
        } else if (choice == 0) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    cout << "\nThanks for using our app :)\n\n";
    return 0;
}