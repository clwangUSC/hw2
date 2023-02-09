#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Movie : public Product {
public:
    Movie(const std::string name, double price, int qty, const std::string genre, std::string rating);

    std::set<std::string> keywords() const;
    std::string displayString();
    void dump(std::ostream& os);
private:
    std::string genre_;
    std::string rating_;
    std::set<std::string> keywords_;

};

#endif