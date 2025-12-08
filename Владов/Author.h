#ifndef AUTHOR_H
#define AUTHOR_H


#include <string>
#include <sstream>


class Author {
private:
std::string name_;
int birthYear_;
public:
Author() : name_("Unknown"), birthYear_(1900) {}
explicit Author(const std::string& name, int birthYear) : name_(name), birthYear_(birthYear) {
setBirthYear(birthYear);
}


std::string getName() const { return name_; }
int getBirthYear() const { return birthYear_; }


void setName(const std::string& name) { name_ = name; }
void setBirthYear(int y) {
if (y < 1850) y = 1850;
if (y > 2025) y = 2025;
birthYear_ = y;
}


std::string to_string() const {
std::ostringstream oss;
oss << name_ << " (" << birthYear_ << ")";
return oss.str();
}
};


#endif 