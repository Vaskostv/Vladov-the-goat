#include <iostream>
#include "Library.h"


int main() {
Library lib;
Author a{"Ivan Vazov", 1850};
Book b1{"Pod igoto", a, 1894, 25.50, "ISBN-001"};
Book b2{"Nema zemya", a, 1900, 18.90, "ISBN-002"};


lib.addBook(b1);
lib.addBook(b2);
lib.addMember(Member{"Petar Petrov", "M001", 2023});


std::cout << lib.to_string() << "\n";


if (lib.loanBook("ISBN-001", "M001", "2025-11-03", "2025-11-17"))
std::cout << "Loan created." << std::endl;


std::cout << "Available ISBN-001? " << std::boolalpha << lib.isBookAvailable("ISBN-001") << std::endl;
lib.returnBook("ISBN-001", "M001");
std::cout << "Available ISBN-001? " << std::boolalpha << lib.isBookAvailable("ISBN-001") << std::endl;


for (const auto& bk : lib.findByAuthor("Vazov")) {
std::cout << bk.to_string() << "\n";
}


std::cout << "Total Book instances alive: " << Book::getTotalBooks() << std::endl;


return 0;
}