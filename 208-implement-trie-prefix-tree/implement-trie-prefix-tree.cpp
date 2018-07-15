// Implement a trie with insert, search, and startsWith methods.
//
// Example:
//
//
// Trie trie = new Trie();
//
// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");   
// trie.search("app");     // returns true
//
//
// Note:
//
//
// 	You may assume that all inputs are consist of lowercase letters a-z.
// 	All inputs are guaranteed to be non-empty strings.
//
//


class TrieNode {
private:
    TrieNode* children[26];
public:
    bool word;

    // Initialize your data structure here.
    TrieNode(){
        word=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }
    
    TrieNode* getChild(char c){
        return children[c-'a'];
    }
    
    void setChild(char c,TrieNode *node){
        children[c-'a']=node;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int len=word.length();
        TrieNode *cur=root;
        for(int i=0;i<len;i++){
            char c=word[i];
            TrieNode *child=cur->getChild(c);
            if(NULL==child){
                TrieNode *newNode=new TrieNode();
                cur->setChild(c,newNode);
                cur=newNode;
            }
            else
                cur=child;
        }
        cur->word=true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int len=word.length();
        TrieNode *cur=root;
        for(int i=0;i<len;i++){
            char c=word[i];
            TrieNode *child=cur->getChild(c);
            if(NULL==child)
                return false;
            else
                cur=child;
        }
        if(cur->word)
            return true;
        else
            return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int len=prefix.length();
        TrieNode *cur=root;
        for(int i=0;i<len;i++){
            char c=prefix[i];
            TrieNode *child=cur->getChild(c);
            if(NULL==child)
                return false;
            else
                cur=child;
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
