// admin.h

#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <iostream>
#include "user.h"
#include "usermanager.h" // الآن يمكننا تضمينه بأمان

class admin : public user {
public:
    admin(const std::string& _name, const std::string& _password) : user(_name, _password) {}
    admin() {}

    // التنفيذ الكامل للدالة موجود الآن داخل الكلاس
    void show_menu(usermanager& manager) override {
        int choice;
        while (true) {
            std::cout << "\n--- Admin Menu ---\n";
            std::cout << "1: View your account\n";
            std::cout << "2: Add a new book\n";
            std::cout << "0: Logout\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                choice = -1;
            }

            if (choice == 1) {
                std::cout << "\nName: " << this->get_name() << std::endl;
            } else if (choice == 2) {
                std::string book_name;
                int no_of_pages;
                std::cout << "\nEnter the book name: ";
                std::cin.ignore();
                std::getline(std::cin, book_name);
                std::cout << "Enter the number of pages: ";
                std::cin >> no_of_pages;

                // هذا الاستدعاء يعمل الآن بدون مشاكل
                manager.add_book(book_name, no_of_pages);

                std::cout << "Book '" << book_name << "' added successfully.\n";
            } else if (choice == 0) {
                break;
            } else {
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};

#endif //ADMIN_H

