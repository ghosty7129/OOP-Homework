#include <iostream>
#include "Library.h"
using namespace std;

int main()
{
    Library lib;

    Author a1{"Robert Greene", 1959};
    Author a2{"James Clear", 1980};       
    Author a3{"Morgan Housel", 1978};    

    Book b1{"48 Laws of Power", a1, 1998, 45.50, "ISBN-001"};
    Book b2{"The Laws of Human Nature", a1, 2018, 40.50, "ISBN-002"};
    Book b3{"Atomic Habits", a2, 2018, 38.00, "ISBN-003"};
    Book b4{"The Psychology of Money", a3, 2020, 50.00, "ISBN-004"};

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);
    lib.addBook(b4);

    Member m1{"Nikola Ivanov", "M001", 2023};
    Member m2{"Maria Petrova", "M002", 2024};
    Member m3{"Ivan Dimitrov", "M003", 2022};

    lib.addMember(m1);
    lib.addMember(m2);
    lib.addMember(m3);

    cout << lib.to_string() << "\n";

    if (lib.loanBook("ISBN-001", "M001", "2025-11-03", "2025-11-17"))
        cout << "Loan for ISBN-001 created.\n";

    if (lib.loanBook("ISBN-003", "M002", "2025-11-04", "2025-11-18"))
        cout << "Loan for ISBN-003 created.\n";

    if (!lib.loanBook("ISBN-001", "M002", "2025-11-05", "2025-11-19"))
        cout << "Cannot loan ISBN-001 to M002 - book not available.\n";

    lib.returnBook("ISBN-001", "M001");
    cout << "Available ISBN-001? " << boolalpha << lib.isBookAvailable("ISBN-001") << "\n";

    cout << "Books by Robert Greene:\n";
    for (const auto& bk : lib.findByAuthor("Robert Greene")) {
        cout << bk.to_string() << "\n";
    }

    cout << "Books by James Clear:\n";
    for (const auto& bk : lib.findByAuthor("James Clear")) {
        cout << bk.to_string() << "\n";
    }

    cout << "Books by Morgan Housel:\n";
    for (const auto& bk : lib.findByAuthor("Morgan Housel")) {
        cout << bk.to_string() << "\n";
    }

    lib.loanBook("ISBN-004", "M003", "2025-11-06", "2025-11-20");
    cout << "Available ISBN-004? " << boolalpha << lib.isBookAvailable("ISBN-004") << "\n";

    lib.returnBook("ISBN-004", "M003");
    cout << "Available ISBN-004 after return? " << boolalpha << lib.isBookAvailable("ISBN-004") << "\n";

    cout << "\nFinal library state:\n" << lib.to_string() << "\n";
}

