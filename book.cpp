#include <sstream>
#include <iomanip>
#include <iostream>
#include "book.h"
#include "util.h"

using namespace std;

Book::Book(const std::string name, double price, int qty, const std::string i, const std::string a)
  :  Product("book", name, price, qty), isbn_(i) , author_(a)
{
    keywords_=parseStringToWords(getName());
    std::set<std::string> tempSet;
    tempSet=parseStringToWords(author_);
    keywords_.insert(tempSet.begin(),tempSet.end());
    keywords_.insert(isbn_);
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