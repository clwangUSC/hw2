#include <sstream>
#include <iomanip>
#include <iostream>
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string name, double price, int qty, const std::string size, const std::string brand)
  :  Product("clothing",name, price, qty), size_(size) , brand_(brand)
{
    keywords_=parseStringToWords(getName());
    std::set<std::string> tempSet;
    tempSet=parseStringToWords(brand_);
    keywords_.insert(tempSet.begin(),tempSet.end());
}

Clothing::~Clothing()
{

}


std::set<std::string> Clothing::keywords() const
{
    return keywords_;
}

bool Clothing::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}

std::string Clothing::displayString() const
{
    stringstream ss; 
    ss << fixed << setprecision(2) << getPrice();   
    string p;
    ss >> p;

    std::string s = "";
    s+=getName();
    s+="\n";
    //cout<<getName()<<endl;
    s+="Size: ";
    s+=size_;
    s+=" Brand: ";
    s+=brand_;
    s+="\n";
    //cout<<"Size: "<<size_<<" Brand: "<<brand_<<endl;
    //s+=to_string(getPrice());
    s+=p;
    s+="  ";
    s+=to_string(getQty());
    s+=" left.";
    //cout<<getPrice()<<" "<<getQty()<<" left."<<endl;
    return s;
}
void Clothing::dump(std::ostream& os) const
{
    os << "clothing" << "\n" << getName() << "\n" << getPrice() << "\n" << getQty() << "\n" << size_ << "\n" << brand_ << endl;
}