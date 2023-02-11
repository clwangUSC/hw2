#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    std::set<std::string> set;
    string temp;
    //idexes of start and end for words in the rawWords
    int startIndex;
    int endIndex;

    for(size_t x=0; x<rawWords.length(); x++)
    {
        if(isalpha(rawWords[x]))
        {     
            startIndex=x;
            //cout<<"!!step in: "<<startIndex<<endl;
            int step = 0;
            bool foundWord = false;
            endIndex=0;
            for(size_t y=x; y<rawWords.length(); y++)
            {
              //cout<<"letter it iterates through: "<<rawWords[y]<<endl;
              if(rawWords[y]==' '||!isalpha(rawWords[y]))
              {
                
                endIndex=y;
                //cout<<"!!stepout: "<<startIndex<<" "<<endIndex<<endl;
                foundWord = true;
              } else if(y==rawWords.length()-1)
              {
                endIndex=y+1;
              }
              if(foundWord)
              {
                //break out of this loop if word is found
                y = rawWords.length();
                foundWord = false;
              }
              step++;
            }
            x+=step-1;
            if(endIndex-startIndex>=2)
            {
                set.insert(convToLower(rawWords.substr(startIndex,endIndex-startIndex)));
            }
            
        }

    }
    // temp = rtrim(rawWords);
    // set.insert(temp);

    return set;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

// int main(int argc, char* argv[])
// {
//   string s;
//   set<string> spl;
//   s = "Men's Fitted Sh";
//   spl = parseStringToWords(s);
//   cout<<"begin"<<endl;
//   for(set<string>::iterator it=spl.begin(); it!=spl.end(); it++)
//   {
//     cout<<*it<<endl;
//   }
//   cout<<"end"<<endl;

  
// }
