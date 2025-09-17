// reading_session.h

#ifndef READING_SESSION_H
#define READING_SESSION_H

#include "book.h"

class reading_session {
private:
    book bok;
    int current_page = 0;
public:
    reading_session() {}
    reading_session(const book& _book, int _current_page) : bok(_book), current_page(_current_page) {}

    void set_current_page(int _current_page) {
        current_page = _current_page;
    }
    int get_current_page() const { // Added const
        return current_page;
    }
    void set_book(const book& _book) { // Pass by const reference
        bok = _book;
    }
    book get_book() const { // Added const
        return bok;
    }
};

#endif //READING_SESSION_H