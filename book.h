#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Book : public Product {
public:
    Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, std::string author);
    ~Book();

    std::set<std::string> keywords() const;
    std::string displayString();
    void dump(std::ostream& os);
private:
    std::string isbn_;
    std::string author_;
    std::set<std::string> keywords_;

};

#endif