#include "Book.h"

Book::Book(std::string a, std::string t, std::string pub, int y, int p) {
    author = a;
    title = t;
    publisher = pub;
    year = y;
    pages = p;
}

std::ostream& operator<<(std::ostream& out, const Book& book) {
    out << "Author: " << book.author << '\n';
    out << "Title: " << book.title << '\n';
    out << "Publisher: " << book.publisher << '\n';
    out << "Year: " << book.year << '\n';
    out << "Pages: " << book.pages << '\n';
    return out;
}

bool Book::operator<(const Book& other) const {
    return title < other.title;
}

bool Book::operator==(const Book& other) const {
    return title == other.title;
}

std::string Book::getTitle() const {
    return title;
}
