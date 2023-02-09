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

Book::~Book()
{

}

std::set<std::string> Book::keywords() const
{
    return keywords_;
}

bool Book::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}

std::string Book::displayString() const
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
void Book::dump(std::ostream& os) const
{
    os << "book" << "\n" << getName() << "\n" << getPrice() << "\n" << getQty() << "\n" << isbn_ << "\n" << author_ << endl;
}