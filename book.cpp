#include <sstream>
#include <iomanip>
#include <iostream>
#include "book.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string i, const std::string a)
  :  Product(category, name, price, qty), isbn_(i) , author_(a)
{
    keywords_.insert(isbn_);
    keywords_.insert(parseStringToWords(getName()));
    keywords_.insert(parseStringToWords(author_));
}


std::set<std::string> Book::keywords() const
{
    return keywords_;
}

std::string Book::displayString()
{
    std::string s = "";
    s+=getName();
    s+="\n";
    cout<<getName()<<endl;
    s+="Author: ";
    s+=author_;
    s+=" ISBN: ";
    s+=isbn_;
    s+="\n";
    cout<<"Author: "<<author_<<" ISBN: "<<isbn_<<endl;
    s+=getPrice();
    s+=" ";
    s+=getQty();
    s+=" left.";
    cout<<getPrice()<<" "<<getQty()<<" left."<<endl;
    return s;
}
void Book::dump(std::ostream& os)
{
    os << "book" << "\n" << getName() << "\n" << getPrice() << "\n" << getQty() << "\n" << isbn_ << "\n" << author_ << endl;
}