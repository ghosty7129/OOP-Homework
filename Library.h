#pragma once
#include <vector>
#include <string>
#include "Book.h"
#include "Member.h"
#include "Loan.h"

class Library {
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Loan> loans;

public:
    void addBook(const Book& b) { books.push_back(b); }
    void addMember(const Member& m) { members.push_back(m); }

    bool hasBook(const std::string& isbn) const {
        for (const auto& b : books)
            if (b.getISBN() == isbn) return true;
        return false;
    }

    bool isBookAvailable(const std::string& isbn) const {
        for (const auto& l : loans)
            if (l.getISBN() == isbn && !l.isReturned()) return false;
        return true;
    }

    bool loanBook(const std::string& isbn, const std::string& memberId, const std::string& start, const std::string& due) {
        if (hasBook(isbn) && isBookAvailable(isbn)) {
            loans.push_back(Loan(isbn, memberId, start, due));
            return true;
        }
        return false;
    }                                                                                                                       

    bool returnBook(const std::string& isbn, const std::string& memberId) {
        for (auto& l : loans) {
            if (l.getISBN() == isbn && l.getMemberId() == memberId && !l.isReturned()) {
                l.markReturned();
                return true;
            }
        }
        return false;
    }

    std::vector<Book> findByAuthor(const std::string& authorName) const {
        std::vector<Book> result;
        for (const auto& b : books)
            if (b.getAuthor().getName().find(authorName) != std::string::npos)
                result.push_back(b);
        return result;
    }

    std::string to_string() const {
        return "Library has " + std::to_string(books.size()) + " books, " + std::to_string(members.size()) + " members, " + std::to_string(loans.size()) + " loans";
    }
};
