#include "mydatastore.h"

using namespace std;
MyDataStore::MyDataStore()
{
    // ifstream file;
    // file.open("database.txt");
    // DBParser p;
    // SectionParser* pParse = new ProductSectionParser();
    // SectionParser* uParse = new UserSectionParser();
    // p.addSectionParser("product", pParse);
    // p.addSectionParser("user", uParse);
    // p.parse("database.txt",this);
    // file.close();
    
}
MyDataStore::~MyDataStore()
{

}
void MyDataStore::addProduct(Product* p)
{  
    products_.insert(p);
    std::set<string> words = p->keywords();

    map<string, std::set<Product*>>::iterator mapFinder;
    for ( std::set<string>::iterator it = words.begin(); it!=words.end(); ++it)
    {
        mapFinder= keyToProduct_.find(*it);
        if(mapFinder!=keyToProduct_.end())
        {
            //if the string exists just add another product pointer to the set 
            (mapFinder->second).insert(p);
        }
        else
        {
            //if the string is not found in the keyToProduct_
            //create a set and put the product in it, link the two 
            //add to the list of keys and producst
            set<Product*> temp;
            temp.insert(p);
            keyToProduct_.insert(pair<string,set<Product*>>(*it,temp));
        }
    }
    
}
void MyDataStore::addUser(User* u)
{
    users_.insert(pair<string,User*>(u->getName(),u));
}
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
    set<Product*> temp;

    temp = keyToProduct_.find(terms[0])->second;

    if(type==0)
    {
        for(size_t x=1; x<terms.size(); x++)
        {
            temp = setIntersection(temp,(keyToProduct_.find(terms[x]))->second);
        }

    }
    else if (type ==1)
    {
        for(size_t x=1; x<terms.size(); x++)
        {
            temp = setUnion(temp,(keyToProduct_.find(terms[x]))->second);
        }
    }

    vector<Product*>output;
    for(set<Product*>::iterator it = temp.begin(); it!= temp.end(); ++it)
    {
        output.push_back(*it);
    }
    return output;
    
}
void MyDataStore::dump(std::ostream& ofile)
{
    ofile<<"<products>"<<endl;
    for(std::set<Product*>::iterator it = products_.begin(); it!=products_.end(); ++it)
    {
        (*it)->dump(ofile);
    }
    ofile<<"</products>"<<endl;
    ofile<<"<users>"<<endl;
    for(std::map<string, User*>::iterator it = users_.begin(); it!=users_.end(); ++it)
    {
        it->second->dump(ofile);
    }    
    ofile<<"</users>"<<endl;

}

void MyDataStore::addToCart(User* u, Product* p)
{
    map<User*,vector<Product*>>::iterator it = carts_.find(u);
    (it->second).push_back(p);


    // for(std::vector<Product*>::iterator it2 = (it->second).begin(); it2!=(it->second).end(); it2++)
    // {
    //     it2->dump(cout);
    // }
}

void MyDataStore::displayCart(User* u)
{
    vector<Product*> cart = (carts_.find(u))->second;
    for(size_t x=0; x<cart.size(); ++x)
    {
        cart[x]->dump(cout);
    }
}

void MyDataStore::buyCart(User* u)
{
    //map<User*,vector<Product*>>::iterator it = carts_.find(u);
    vector<Product*> cart = (carts_.find(u))->second;

    for(size_t x=0; x<cart.size(); ++x)
    {
        if(cart[x]->getQty()>0&&(u->getBalance()>=cart[x]->getPrice()))
        {
            cart[x]->subtractQty(1);
            u->deductAmount(cart[x]->getPrice());        
        }
    }
}

User* MyDataStore::returnUser(std::string un)
{
    return users_.find(un)->second;
}