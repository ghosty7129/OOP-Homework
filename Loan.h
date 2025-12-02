#pragma once
#include <string>

class Loan {
    std::string isbn;
    std::string memberId;
    std::string startDate;
    std::string dueDate;
    bool returned = false;

public:
    Loan(const std::string &i, const std::string &m, const std::string &s, const std::string &d) : isbn(i), memberId(m), startDate(s), dueDate(d) {
        if (dueDate < startDate) dueDate = startDate;
    }

    void markReturned() { 
        returned = true; 
    }

    bool isOverdue(const std::string& today) const { 
        return !returned && today > dueDate; 
    }

    std::string getISBN() const { 
        return isbn; 
    }

    std::string getMemberId() const { 
        return memberId; 
    }

    bool isReturned() const { 
        return returned; 
    }

    std::string to_string() const {
        return "Loan: ISBN " + isbn + ", Member " + memberId + ", Start: " + startDate + ", Due: " + dueDate + ", Returned: " + (returned ? "Yes" : "No");
    }
};
