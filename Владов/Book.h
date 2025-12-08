#ifndef BOOK_H
#define BOOK_H


#include <string>
#include <sstream>
#include "Author.h"


class Book {
private:
std::string title_;
Author author_;
int year_;
double price_;
std::string isbn_;


void init_common() {
++totalBooks;
}
public:
static int totalBooks;


Book() : title_("Untitled"), author_(), year_(1900), price_(0.0), isbn_("") { init_common(); }


Book(const std::string& title, const Author& author, int year, double price, const std::string& isbn)
: title_(title), author_(author), year_(year), price_(price), isbn_(isbn) {
setYear(year);
setPrice(price);
init_common();
}


Book(const Book& other) = default;
Book(Book&& other) noexcept = default;
Book& operator=(const Book& other) = default;
Book& operator=(Book&& other) noexcept = default;
~Book() { --totalBooks; }


std::string getTitle() const { return title_; }
Author getAuthor() const { return author_; }
int getYear() const { return year_; }
double getPrice() const { return price_; }
std::string getIsbn() const { return isbn_; }


void setTitle(const std::string& t) { title_ = t; }
void setAuthor(const Author& a) { author_ = a; }
void setYear(int y) { if (y < 1450) y = 1450; if (y > 2025) y = 2025; year_ = y; }
void setPrice(double p) { if (p < 0.0) p = 0.0; price_ = p; }
void setIsbn(const std::string& i) { isbn_ = i; }


std::string to_string() const {
std::ostringstream oss;
oss << "\"" << title_ << "\" by " << author_.to_string()
<< " | " << year_ << " | " << "price=" << price_ << " | ISBN=" << isbn_;
return oss.str();
}


static int getTotalBooks() { return totalBooks; }
};


#endif 