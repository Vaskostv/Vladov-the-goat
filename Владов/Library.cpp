#include "Library.h"
#include <algorithm>
#include <sstream>

Library::Library() = default;

void Library::addBook(const Book& b) {
    if (b.getIsbn().empty()) return;

    // предотвратяване на дублиране
    if (!hasBook(b.getIsbn()))
        books_.push_back(b);
}

void Library::addMember(const Member& m) {
    if (m.getMemberId().empty()) return;

    auto it = std::find_if(members_.begin(), members_.end(),
                           [&](const Member& mem) { return mem.getMemberId() == m.getMemberId(); });

    if (it == members_.end())
        members_.push_back(m);
}

bool Library::hasBook(const std::string& isbn) const {
    return std::any_of(books_.begin(), books_.end(),
                       [&](const Book& b) { return b.getIsbn() == isbn; });
}

bool Library::isBookAvailable(const std::string& isbn) const {
    if (!hasBook(isbn)) return false;

    // налична е, ако няма активен заем
    return std::none_of(loans_.begin(), loans_.end(),
                        [&](const Loan& ln) {
                            return ln.getIsbn() == isbn && !ln.isReturned();
                        });
}

bool Library::loanBook(const std::string& isbn,
                       const std::string& memberId,
                       const std::string& start,
                       const std::string& due) {
    if (!hasBook(isbn)) return false;

    auto it = std::find_if(members_.begin(), members_.end(),
                           [&](const Member& m) { return m.getMemberId() == memberId; });

    if (it == members_.end()) return false;        // няма такъв читател
    if (!isBookAvailable(isbn)) return false;      // книгата е заета

    try {
        loans_.emplace_back(isbn, memberId, start, due);
    } catch (...) {
        return false;
    }
    return true;
}

bool Library::returnBook(const std::string& isbn, const std::string& memberId) {
    for (auto& ln : loans_) {
        if (ln.getIsbn() == isbn &&
            ln.getMemberId() == memberId &&
            !ln.isReturned()) {

            ln.markReturned();
            return true;
        }
    }
    return false;
}

std::vector<Book> Library::findByAuthor(const std::string& authorName) const {
    std::vector<Book> result;

    for (const auto& b : books_) {
        if (b.getAuthor().getName().find(authorName) != std::string::npos)
            result.push_back(b);
    }

    return result;
}

std::string Library::to_string() const {
    std::ostringstream oss;

    int activeLoans = 0;
    for (const auto& ln : loans_)
        if (!ln.isReturned()) activeLoans++;

    oss << "Library: books=" << books_.size()
        << " members=" << members_.size()
        << " activeLoans=" << activeLoans;

    return oss.str();
}
