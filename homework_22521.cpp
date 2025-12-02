#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Author 
class Author
{
    string name{"Unknown"};
    int birthYear{1900};

public:
    Author() = default;
    Author(string n, int y) : name(n), birthYear(y) {}

    string getName() const { 
        return name; 
    }

    int getBirthYear() const { 
        return birthYear; 
    }

    void setBirthYear(int y)
    {
        if (y >= 1900 && y <= 2025)
            birthYear = y;
    }

    string to_string() const
    {
        return name + " (" + std::to_string(birthYear) + ")";
    }
};

// Book 
class Book
{
    string title;
    Author author;
    int year{0};
    double price{0};
    string isbn;

    static int totalBooks;

public:
    Book() { 
        totalBooks++; 
    }

    Book(string t, Author a, int y, double p, string i) : title(t), author(a), year(y), price(p), isbn(i) { 
        totalBooks++; 
    }

    Book(const Book& other) = default;
    Book(Book&& other) = default;
    Book& operator=(const Book& other) = default;
    Book& operator=(Book&& other) = default;
    
    ~Book() { 
        totalBooks--; 
    }

    string getTitle() const { 
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

    string getISBN() const { 
        return isbn; 
    }

    void setYear(int y)
    {
        if (y >= 1000 && y <= 2050)
            year = y;
    }
    void setPrice(double p)
    {
        if (p >= 0)
            price = p;
    }

    string to_string() const
    {
        return title + " by " + author.getName() + ", " + std::to_string(year) + ", " + std::to_string(price) + " BGN, ISBN: " + isbn;
    }

    static int getTotalBooks() { 
        return totalBooks; 
    }
};

int Book::totalBooks = 0;

// Member 
class Member
{
    string name;
    string memberId;
    int yearJoined{0};

public:
    Member() = default;
    Member(string n, string id, int y) : name(n), memberId(id), yearJoined(y) {}

    string getName() const { 
        return name; 
    }

    string getMemberId() const { 
        return memberId; 
    }

    int getYearJoined() const { 
        return yearJoined; 
    }

    string to_string() const
    {
        return name + " (" + memberId + "), joined: " + std::to_string(yearJoined);
    }
};

// Loan 
class Loan
{
    string isbn;
    string memberId;
    string startDate;
    string dueDate;
    bool returned{false};

public:
    Loan(string i, string m, string s, string d) : isbn(i), memberId(m), startDate(s), dueDate(d)
    {
        if (dueDate < startDate)
            dueDate = startDate;
    }

    void markReturned() { returned = true; }
    bool isOverdue(const string& today) const { return !returned && today > dueDate; }

    string getISBN() const { 
        return isbn; 
    }

    string getMemberId() const { 
        return memberId; 
    }

    bool isReturned() const { 
        return returned; 
    }

    string to_string() const
    {
        return "Loan: ISBN " + isbn + ", Member " + memberId + ", Start: " + startDate + ", Due: " + dueDate + ", Returned: " + (returned ? "Yes" : "No");
    }
};

//  Library 
class Library
{
    vector<Book> books;
    vector<Member> members;
    vector<Loan> loans;

public:
    void addBook(const Book& b) { 
        books.push_back(b); 
    }

    void addMember(const Member& m) { 
        members.push_back(m); 
    }

    bool hasBook(const string& isbn) const
    {
        for (const auto& b : books)
            if (b.getISBN() == isbn)
                return true;
        return false;
    }

    bool isBookAvailable(const string& isbn) const
    {
        for (const auto& l : loans)
            if (l.getISBN() == isbn && !l.isReturned())
                return false;
        return true;
    }

    bool loanBook(const string& isbn, const string& memberId, const string& start, const string& due)
    {
        if (hasBook(isbn) && isBookAvailable(isbn))
        {
            loans.push_back(Loan(isbn, memberId, start, due));
            return true;
        }
        return false;
    }

    bool returnBook(const string& isbn, const string& memberId)
    {
        for (auto& l : loans)
        {
            if (l.getISBN() == isbn && l.getMemberId() == memberId && !l.isReturned())
            {
                l.markReturned();
                return true;
            }
        }
        return false;
    }

    vector<Book> findByAuthor(const string& authorName) const
    {
        vector<Book> result;
        for (const auto& b : books)
        {
            if (b.getAuthor().getName().find(authorName) != string::npos)
                result.push_back(b);
        }
        return result;
    }

    string to_string() const
    {
        return "Library has " + std::to_string(books.size()) + " books, " + std::to_string(members.size()) + " members, " + std::to_string(loans.size()) + " loans";
    }
};
