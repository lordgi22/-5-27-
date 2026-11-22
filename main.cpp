#include <iostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include <string>
#include <functional>
#include "Book.h"

struct BookHash {
    size_t operator()(const Book& book) const {
        return std::hash<std::string>()(book.getTitle());
    }
};

int main() {
    int count;

    std::ifstream input("C:/Users/forti/OneDrive/Desktop/input.txt");

    if (!input.is_open()) {
        std::cout << "File is not found" << '\n';
        return 1;
    }

    input >> count;
    input.ignore();

    std::string author;
    std::string title;
    std::string publisher;
    int year;
    int pages;

    std::set<Book> books;
    std::unordered_set<Book, BookHash> unorderedBooks;

    for (int j = 0; j < count; j++) {
        std::getline(input, author);
        std::getline(input, title);
        std::getline(input, publisher);
        input >> year;
        input >> pages;
        input.ignore();

        Book b(author, title, publisher, year, pages);

        books.insert(b);
        unorderedBooks.insert(b);
    }

    std::ofstream output("C:/Users/forti/OneDrive/Desktop/output5.txt");

    output << "Set:" << '\n';

    for (auto it = books.begin(); it != books.end(); ++it) {
        output << *it << '\n';
    }

    output << "Unordered set:" << '\n';

    for (auto it = unorderedBooks.begin(); it != unorderedBooks.end(); ++it) {
        output << *it << '\n';
    }

    std::cout << "Done!" << '\n';

    return 0;
}
