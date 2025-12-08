#ifndef LOAN_H
#define LOAN_H


#include <string>
#include <sstream>
#include <stdexcept>


class Loan {
private:
std::string isbn_;
std::string memberId_;
std::string startDate_; 
std::string dueDate_;
bool returned_;
public:
Loan(const std::string& isbn, const std::string& memberId,
const std::string& startDate, const std::string& dueDate)
: isbn_(isbn), memberId_(memberId), startDate_(startDate), dueDate_(dueDate), returned_(false) {
if (dueDate_ < startDate_) throw std::invalid_argument("dueDate < startDate");
}


std::string getIsbn() const { return isbn_; }
std::string getMemberId() const { return memberId_; }
std::string getStartDate() const { return startDate_; }
std::string getDueDate() const { return dueDate_; }
bool isReturned() const { return returned_; }


void markReturned() { returned_ = true; }


bool isOverdue(const std::string& today) const {
if (returned_) return false;
return today > dueDate_; 
}


std::string to_string() const {
std::ostringstream oss;
oss << "ISBN=" << isbn_ << " Member=" << memberId_ << " " << startDate_ << "->" << dueDate_
<< " returned=" << (returned_ ? "yes" : "no");
return oss.str();
}
};


#endif 