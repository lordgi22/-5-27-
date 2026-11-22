#pragma once
#include <string>
#include <iostream>

class Book {
private:
    std::string author;
    std::string title;
    std::string publisher;
    int year;
    int pages;

public:
    Book(std::string a, std::string t, std::string pub, int y, int p);

    friend std::ostream& operator<<(std::ostream& out, const Book& book);

    bool operator<(const Book& other) const;
    bool operator==(const Book& other) const;

    std::string getTitle() const;
};
