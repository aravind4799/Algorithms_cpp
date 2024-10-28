#include<bits/stdc++.h>
using namespace std;

struct trie{
    bool isEnd;
    vector<trie*> children;

    trie(){
        for(int i=0;i<26;i++){
            this->children.push_back(nullptr);
        }
        this->isEnd = false;
    }

    void insert(string word){
        trie* root = this;
        trie* currNode = root;
        for(auto it: word){
    
            if(currNode->children[it-'a']==nullptr){
                currNode->children[it-'a'] = new trie();
            }
            currNode = currNode->children[it-'a'];
        }
        currNode->isEnd = true;
    }

    bool doesWordExist(string word){
        trie* currNode = this;
        for(auto it: word){
            if(currNode->children[it-'a']==nullptr) return false;
            currNode = currNode->children[it-'a'];
        }
        if(currNode->isEnd) return true;
        return false;
    }

    bool findPrefix(string word){
        trie* currNode = this;
        for(int i=0;i<word.size();i++){
            if(currNode->children[word[i]-'a']==nullptr) return false;
            currNode = currNode->children[word[i]-'a'];
        }
        return true;
        
    }
};
int main(){
    vector<string> words = {"abc","abcd","bcd","bc","cd","cda"};
    trie* root = new trie();
    for(auto word: words){
        root->insert(word);
    }
    if(root->doesWordExist("abc"))cout<<"word exist";
    else cout<<"word doesn't exist";
    cout<<endl;

    if(root->findPrefix("z")) cout<<"prefix exist";
    else cout<<"prefix does not exist";
    cout<<endl;
    return 0;
}