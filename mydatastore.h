#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "datastore.h"
#include "fstream"
#include "db_parser.h"
#include "util.h"
#include <set>
#include <map>

class MyDataStore : public DataStore
{
public:
    MyDataStore();
    ~MyDataStore();
    void addProduct(Product* p);
    void addUser(User* u);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void dump(std::ostream& ofile);
    void addToCart(User* u, Product* p);
    void displayCart(User* u);
    void buyCart(User* u);
    User* returnUser(std::string un);
private:
    std::map<std::string , User*> users_;
    std::set<Product*> products_;
    std::map<std::string, std::set<Product*>> keyToProduct_;
    std::map<User*, std::vector<Product*>> carts_;
};
#endif