#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class WordDictionary {
    vector<string> dict;

public:

    // Adds a word into the data structure.
    void addWord(string word) {
        dict.push_back(word);
        cout<<"added "<<word<<endl;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        string tword = word;
        vector<int> v{};

        int a=0;
        for(int is=0; is<tword.size(); is++){
            if(tword[is]== '.')
                v.push_back(is);
        }

        int case_num = pow(26,v.size());

        for(int icase=0; icase<case_num; icase++){
            char s;
            int ca=icase;
            for(int ic = 0; ic<v.size(); ic++){
                s = ca%26+'a';
                ca/=26;
                tword[v[ic]] = s;
            }
            if(find(dict.cbegin(),dict.cend(), static_cast<const string&>(tword))!= dict.end()) {cout<<1<<endl;return true;}
        }
        cout<<0<<endl;
        return false;
    }
};

int main(){
    WordDictionary wd;
    wd.addWord("ran"),wd.addWord("rune"),wd.addWord("runner"),wd.addWord("runs"),wd.addWord("add"),wd.addWord("adds"),wd.addWord("adder"),wd.addWord("addee");
    wd.search("r.n"),
    wd.search("ru.n.e"),
    wd.search("add"),
    wd.search("add."),
    wd.search("adde."),
    wd.search(".an."),
    wd.search("...s"),
    wd.search("....e."),
    wd.search("......."),
    wd.search("..n.r");
    return 0;
}