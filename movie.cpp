#include <sstream>
#include <iomanip>
#include <iostream>
#include "movie.h"
#include "util.h"

using namespace std;

Movie::Movie(const std::string name, double price, int qty, const std::string genre, const std::string rating)
  :  Product("movie", name, price, qty), genre_(genre) , rating_(rating)
{
    keywords_=parseStringToWords(getName());
    keywords_.insert(convToLower(genre_));
}

Movie::~Movie()
{

}

std::set<std::string> Movie::keywords() const
{
    return keywords_;
}

bool Movie::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}

std::string Movie::displayString() const
{
    stringstream ss; 
    ss << fixed << setprecision(2) << getPrice();   
    string p;
    ss >> p;

    std::string s = "";
    s+=getName();
    s+="\n";
    //cout<<getName()<<endl;
    s+="Genre: ";
    s+=genre_;
    s+=" Rating: ";
    s+=rating_;
    s+="\n";
    //cout<<"Genre: "<<genre_<<" Rating: "<<rating_<<endl;
    //s+=to_string(getPrice());
    s+= p;
    s+="  ";
    s+=to_string(getQty());
    s+=" left.";
    //cout<<getPrice()<<" "<<getQty()<<" left."<<endl;
    return s;
}
void Movie::dump(std::ostream& os) const
{
    os << "movie" << "\n" << getName() << "\n" << getPrice() << "\n" << getQty() << "\n" << genre_ << "\n" << rating_ << endl;
}