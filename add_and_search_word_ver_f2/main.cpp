#include <iostream>
#include <vector>
using namespace std;
struct TrieNode{
    char letter{0};
    vector<TrieNode*> nxtltrs;
};

class WordDictionary {
    TrieNode* root =new TrieNode;

public:
    // Adds a word into the data structure.
    void addWord(string word) {
        word+= static_cast<char>(0);
        cout<<root->nxtltrs.size()<<endl;
        TrieNode* cur = root;
        bool found{false};
        for(int curc=0; curc< word.size(); curc++){
            found = false;
            for(TrieNode* nxtltr : cur->nxtltrs){
                if(nxtltr->letter == word[curc]){
                    cur = nxtltr;
                    found = true;
                    break;
                }
            }
            if(!found){
                TrieNode* new_node = new TrieNode;
                new_node->letter=word[curc];
                cur->nxtltrs.push_back(new_node);
                cur=new_node;
            }
        }
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        word+= static_cast<char>(0);
        TrieNode *cur = root;

        vector<TrieNode*> rxpr_p_stk{};
        vector<int> rxpr_n_stk{};
        vector<int> rxpr_curc_stk{};

        bool found{false};
        int curc{0};
        while (curc < word.size()) {
            found = false;
            if (word[curc] == '.') {
                //cout<<rxpr_curc_stk.size()-1<0;
                if (rxpr_curc_stk.size()<1) {
                    rxpr_curc_stk.push_back(curc);
                    rxpr_p_stk.push_back(cur);
                    rxpr_n_stk.push_back(0);
                }
                else if (rxpr_curc_stk[rxpr_curc_stk.size() - 1] != curc) {
                    rxpr_curc_stk.push_back(curc);
                    rxpr_p_stk.push_back(cur);
                    rxpr_n_stk.push_back(0);
                }
                else {
                    rxpr_n_stk[rxpr_n_stk.size()-1]++;
                }

                if (rxpr_n_stk[rxpr_n_stk.size()-1]>=cur->nxtltrs.size()){
                    rxpr_curc_stk.pop_back();
                    rxpr_n_stk.pop_back();
                    rxpr_p_stk.pop_back();
                    found = false;
                }
                else{
                    cur = cur->nxtltrs[rxpr_n_stk[rxpr_n_stk.size()-1]];
                    curc ++;
                    found = true;
                }

            }
            else {
                for (TrieNode *nxtltr : cur->nxtltrs) {
                    if (nxtltr->letter == word[curc]) {
                        cur = nxtltr;
                        curc ++;
                        found = true;
                        break;
                    }
                }
            }

            if (!found) {
                if (rxpr_curc_stk.size() > 0) {
                    curc = rxpr_curc_stk[rxpr_curc_stk.size()-1];
                    cur = rxpr_p_stk[rxpr_p_stk.size()-1];
                }
                else {
                    cout << false << endl;
                    return false;
                }
            }
        }

        cout<<true<<endl;
        return true;
    }
};



int main(){
    WordDictionary wd;
    wd.addWord("ran");
    wd.addWord("rune");
    wd.addWord("runner"),wd.addWord("runs"),wd.addWord("add"),wd.addWord("adds"),wd.addWord("adder"),wd.addWord("addee");

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