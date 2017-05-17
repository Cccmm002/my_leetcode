// Design a data structure that supports the following two operations:
//
//
// void addWord(word)
// bool search(word)
//
//
//
// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
//
//
// For example:
//
// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true
//
//
//
// Note:
// You may assume that all words are consist of lowercase letters a-z.
//
//
// click to show hint.
//
// You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.


class WordDictionary {
private:
    typedef struct TrieNode {
        bool word;
        TrieNode *children[26];
        
        inline TrieNode* getChild(char c){
            return children[c-'a'];
        }
        
        inline void setChild(char c, TrieNode *node){
            children[c-'a']=node;
        }
        
        TrieNode(){
            word=false;
            for(int i=0;i<26;i++)
                children[i]=NULL;
        }
    }*pTrieNode;
    
    pTrieNode root;
public:

    WordDictionary() {
        root=new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        int len=word.length();
        pTrieNode cur=root;
        for(int i=0;i<len;i++){
            pTrieNode n=cur->getChild(word[i]);
            if(NULL==n){
                pTrieNode newNode=new TrieNode();
                cur->setChild(word[i],newNode);
                cur=newNode;
            }
            else
                cur=n;
        }
        cur->word=true;
    }
    
    bool find(string word, pTrieNode r){
        if(word=="")
            return r->word;
        char c=word[0];
        if(c=='.'){
            for(int i=0;i<26;i++){
                if(r->children[i]==NULL) continue;
                bool next=find(word.substr(1),r->children[i]);
                if(next) return true;
            }
            return false;
        }
        pTrieNode n=r->getChild(c);
        if(n==NULL) return false;
        else return find(word.substr(1),n);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return find(word,root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
