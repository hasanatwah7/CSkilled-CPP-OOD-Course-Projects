#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <ctype.h>
#include <climits>
#include <iomanip>
#include <numeric>
#include <bitset>
#include <functional>
#include <iterator>
#include <sstream>

#define long long ll;
#define long double ld;


using namespace std;

struct user;

struct book {
    string name;
    int id;
    short quantity;
    vector<user> whoborrowedit;
};

struct user {
    string name;
    int id;
    vector<book> borrowed_books;
};


string prefsrch(string s, string main) {
    size_t pos = main.find(s);
    if (pos == 0) {
        return main;
    }
    else
        return "";
}

bool bsortbooksbyname(book b1, book b2)
{
    return b1.name < b2.name;
}

void sortbooksbyname(vector<book> &vec)
{
    sort(vec.begin(), vec.end(), bsortbooksbyname);
}

bool bsortbooksbyid(book b1, book b2)
{
    return b1.id < b2.id;
}

void sortbooksbyid(vector<book> &vec)
{
    sort(vec.begin(), vec.end(), bsortbooksbyid);
}

unsigned main()
{
    vector<book> books;
    vector<user> users;
    

    cout << "*************************************\n";
    cout << "*********** W E L C O M E ***********\n";
    cout << "*************************************\n\n";

    cout << "Library Menu:\n";
    cout << "1) add_book\n";
    cout << "2) search_books_by_prefix\n";
    cout << "3) print_who_borrowed_book_by_name\n";
    cout << "4) print_library_by_id\n";
    cout << "5) print_library_by_name\n";
    cout << "6) add_user\n";
    cout << "7) user_borrow_book\n";
    cout << "8) user_return_book\n";
    cout << "9) print_users\n";
    cout << "\nPress 0 to Exit...\n\n";

    int choice{};
    while (1) {
        cout << "Enter your menu choice [1 - 10]: ";
        cin >> choice;
        if (choice == 0)
            break;
        else if (choice == 1)
        {
            book temp;
            cout << "Enter book name, id, quantity: ";
            cin >> temp.name >> temp.id >> temp.quantity;
            books.push_back(temp);
            cout << "Book Added!\n";
        }
        else if (choice == 2)
        {
            cout << "Enter the name you wanna search about: ";
            string temp;
            cin >> temp;
            for (int i{}; i < books.size(); ++i)
            {
                if (prefsrch(temp, books[i].name) != "")
                {
                    cout << books[i].name << " we have " << books[i].quantity << " copies\n";
                }
            }
            cout << "that's all :)\n";
        }
        else if (choice == 3)
        {
            string temp;
            cout << "Enter the name of the book: ";
            cin >> temp;
            for (int i{}; i < books.size(); ++i)
            {
                if (books[i].name == temp) {
                    for (int j{}; j < books[i].whoborrowedit.size(); ++j)
                    {
                        cout << books[i].whoborrowedit[j].name << ' ';
                    }
                    cout << endl;
                    break;
                }
            }
        }
        else if (choice == 4)
        {
            sortbooksbyid(books);
            for (int i{}; i < books.size(); ++i)
            {
                cout << "id: " << books[i].id << "    name: " << books[i].name << "    total quantity: " <<
                    books[i].quantity << "    total users who borrowed it: " << books[i].whoborrowedit.size() << endl;
            }
        }
        else if (choice == 5)
        {
            sortbooksbyname(books);
            for (int i{}; i < books.size(); ++i)
            {
                cout << "id: " << books[i].id << "    name: " << books[i].name << "    total quantity: " <<
                    books[i].quantity << "    total users who borrowed it: " << books[i].whoborrowedit.size() << endl;
            }
        }
        else if (choice == 6)
        {
            user temp;
            cout << "Enter his name followed by his national id: ";
            cin >> temp.name >> temp.id;
            users.push_back(temp);
        }
        else if (choice == 7)
        {
            cout << "Enter user name followed by the book name: ";
            string username;
            string bookname;
            cin >> username >> bookname;
            int bookindx{}, userindx{};
            
            for (int i{}; i < books.size(); ++i)
            {
                if (books[i].name == bookname) {
                    bookindx = i;
                    break;
                }
            }
            if (books[bookindx].quantity > 0) {
            for (int i{}; i < users.size(); ++i)
            {
                if (users[i].name == username) {

                    userindx = i;
                    break;
                }
            }
            books[bookindx].whoborrowedit.push_back(users[userindx]);
            books[bookindx].quantity--;
            users[userindx].borrowed_books.push_back(books[bookindx]);
            }
            else
            {
                cout << "Sorry, there is no copies of this book avaliable rn\n";
            }
        }
        else if (choice == 8)
        {
            //on progress
            cout << "Enter user name followed by the book name: ";
            string username;
            string bookname;
            cin >> username >> bookname;
            int bookindx{}, userindx;

            for (int i{}; i < books.size(); ++i)
            {
                if (books[i].name == bookname)
                    bookindx = i;
            }

            for (int i{}; i < users.size(); ++i)
            {
                if (users[i].name == username)
                    userindx = i;
            }
            
            auto wbindex = books[bookindx].whoborrowedit.begin();
            auto ubindex = users[userindx].borrowed_books.begin();

            for (int i{}; i < books[bookindx].whoborrowedit.size(); ++i)
            {
                if (books[bookindx].whoborrowedit[i].name == username)
                    wbindex = books[bookindx].whoborrowedit.begin() + i;
            }

            for (int i{}; i < users[userindx].borrowed_books.size(); ++i)
            {
                if (users[userindx].borrowed_books[i].name == bookname)
                    ubindex = users[userindx].borrowed_books.begin() + i;
            }

            //find(books[bookindx].whoborrowedit.begin(), books[bookindx].whoborrowedit.end(), username);
            //find(users[userindx].borrowed_books.begin(), users[userindx].borrowed_books.end(), username);

            books[bookindx].quantity++;
            books[bookindx].whoborrowedit.erase(wbindex);
            users[userindx].borrowed_books.erase(ubindex);

        }
        else if (choice == 9)
        {
            for (int i{}; i < users.size(); ++i)
            {
                cout << "user: " << users[i].name << "    id: " << users[i].id;
                
                if (users[i].borrowed_books.size() > 0) {
                    cout << "    borrowed books ids: ";
                    for (int j{}; j < users[i].borrowed_books.size(); ++j)
                    {
                        cout << users[i].borrowed_books[j].id << ' ';
                    }
                }
                cout << endl;
            }
        }
        else
        {
            cout << "I'VE SAID FROM 1 TO 9, YOU FATFUCK";
            continue;
        }

    }
    cout << "Thank you for using our program XD";

}
