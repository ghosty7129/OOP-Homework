#pragma once
#include <string>
#include "Author.h"

class Book {

    std::string title;
    Author author;
    int year;
    double price;
    std::string isbn;

    static int totalBooks;

public:
    Book() { 
        totalBooks++; 
    }

    Book(const std::string &t, const Author &a, int y, double p, const std::string &i) : title(t), author(a), year(y), price(p), isbn(i) { 
        totalBooks++; 
    }

    Book(const Book& other) : title(other.title), author(other.author), year(other.year), price(other.price), isbn(other.isbn) {
        ++totalBooks;
    }

    Book(Book&& other) noexcept : title(std::move(other.title)), author(std::move(other.author)), year(other.year), price(other.price), isbn(std::move(other.isbn)) {
        ++totalBooks;
    }

    Book& operator=(const Book& other) {
        if (this != &other) {
            title = other.title;
            author = other.author;
            year = other.year;
            price = other.price;
            isbn = other.isbn;
        }

        return *this;
    }

    Book& operator=(Book&& other) noexcept {
        if (this != &other) {
            title = std::move(other.title);
            author = std::move(other.author);
            year = other.year;
            price = other.price;
            isbn = std::move(other.isbn);
        }

        return *this;
    }

    ~Book() { 
        totalBooks--; 
    }

    std::string getTitle() const { 
        return title; 
    }

    Author getAuthor() const { 
        return author; 
    }

    int getYear() const { 
        return year; 
    }

    double getPrice() const { 
        return price; 
    }

    std::string getISBN() const { 
        return isbn; 
    }

    void setYear(int y) { 
        if (y >= 1750 && y <= 2050) year = y; 
    }

    void setPrice(double p) { 
        if (p >= 0) price = p; 
    }

    std::string to_string() const {
        return title + " by " + author.getName() + ", " + std::to_string(year) + ", " + std::to_string(price) + " BGN, ISBN: " + isbn;
    }

    static int getTotalBooks() { 
        return totalBooks; 
    }
};

int Book::totalBooks = 0;
