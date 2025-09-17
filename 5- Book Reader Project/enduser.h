// enduser.h

#ifndef ENDUSER_H
#define ENDUSER_H

#include "user.h"
#include "usermanager.h"
#include "reading_session.h"
#include <vector>
#include <iostream>

class usermanager;

class enduser : public user {
private:
    vector<reading_session> sessions;

public:
    enduser(string _name, string _password) : user(_name, _password) {}
    enduser() {}

    void start_new_session(const book& _book) {
        sessions.emplace_back(_book, 0); // Start session with the book at page 0
        cout << "\nNew session started for book: " << _book.get_name() << endl;
    }

    void print_sessions() {
        if (sessions.empty()) {
            cout << "You have no previous reading sessions.\n";
            return;
        }
        cout << "\n--- Your Reading Sessions ---\n";
        for (size_t i = 0; i < sessions.size(); ++i) { // Fixed infinite loop
            cout << i + 1 << ": " << sessions[i].get_book().get_name()
                 << " (Page: " << sessions[i].get_current_page() << "/" << sessions[i].get_book().get_no_of_pages() << ")\n";
        }
    }

    void browse_book(reading_session& session) { // Pass session by reference
        int choice{};
        while (true) {
            cout << "\nCurrent page: " << session.get_current_page() << "/" << session.get_book().get_no_of_pages() << endl;
            cout << "1: Next Page\n";
            cout << "2: Previous Page\n";
            cout << "0: End session\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) { // Fixed logic for Next Page
                if (session.get_current_page() < session.get_book().get_no_of_pages()) {
                    session.set_current_page(session.get_current_page() + 1);
                } else {
                    cout << "You've reached the end of the book.\n";
                }
            } else if (choice == 2) { // Fixed logic for Previous Page
                if (session.get_current_page() > 0) {
                    session.set_current_page(session.get_current_page() - 1);
                } else {
                    cout << "You are at the first page.\n";
                }
            } else if (choice == 0) {
                cout << "Ending session. Your progress is saved.\n";
                return;
            } else {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    void show_menu(usermanager& manager) override {
        int choice;
        while (true) {
            cout << "\n--- User Menu ---\n";
            cout << "1: View your profile\n";
            cout << "2: View your reading sessions\n";
            cout << "3: Start a new session\n";
            cout << "0: Logout\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                cout << "\nName: " << this->get_name() << endl;
            } else if (choice == 2) {
                print_sessions();
                if (sessions.empty()) continue;
                int indx;
                cout << "\nChoose a session by index to browse (or 0 to go back): ";
                cin >> indx;
                if (indx > 0 && indx <= sessions.size()) {
                    browse_book(sessions[indx - 1]); // Pass the actual session
                }
            } else if (choice == 3) {
                vector<book>& books_list = manager.get_books();
                if (books_list.empty()) {
                    cout << "\nSorry, no books are available in the library yet.\n";
                    continue;
                }
                cout << "\n--- Available Books ---\n";
                for (size_t i = 0; i < books_list.size(); ++i) {
                    cout << i + 1 << ": " << books_list[i].get_name() << endl;
                }
                cout << "\nEnter name of the book: ";
                string book_name;
                cin.ignore();
                getline(cin, book_name);
                bool book_found = false;
                for (const auto& current_book : books_list) {
                    if (book_name == current_book.get_name()) {
                        start_new_session(current_book);
                        book_found = true;
                        break;
                    }
                }
                if (!book_found) cout << "Book not found.\n";
            } else if (choice == 0) {
                break;
            } else {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};

#endif //ENDUSER_H