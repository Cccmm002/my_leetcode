// Given a 2D board and a list of words from the dictionary, find all words in the board.
//
//
// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
//
//
//
// For example,
// Given words = ["oath","pea","eat","rain"] and board = 
//
// [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
//
//
// Return ["eat","oath"].
//
//
//
// Note:
// You may assume that all inputs are consist of lowercase letters a-z.
//
//
// click to show hint.
//
// You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?
//
// If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.


class Solution {
private:
    class TrieNode {
    public:
        TrieNode* children[26];
        string word;
    
        // Initialize your data structure here.
        TrieNode(){
            word="";
            for(int i=0;i<26;i++)
                children[i]=NULL;
        }
        
        inline TrieNode* getChild(char c){
            return children[c-'a'];
        }
        
        inline void setChild(char c,TrieNode *node){
            children[c-'a']=node;
        }
    };

    class Trie {
    public:
        TrieNode* root;
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
            cur->word=word;
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
            if(cur->word!="")
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
    };
    
public:
    void search(int x, int y, vector<vector<char>>& board, TrieNode *root, bool *visited, vector<string>& result){
        if(root->word!="") 
            result.push_back(root->word);
        int height=board.size();
        int width=board[0].size();
        visited[y*width+x]=true;
        if(x>0 && !visited[y*width+x-1]){
            TrieNode *child=root->getChild(board[y][x-1]);
            if(child!=NULL)
                search(x-1,y,board,child,visited,result);
        }
        if(x<width-1 && !visited[y*width+x+1]){
            TrieNode *child=root->getChild(board[y][x+1]);
            if(child!=NULL)
                search(x+1,y,board,child,visited,result);
        }
        if(y>0 && !visited[(y-1)*width+x]){
            TrieNode *child=root->getChild(board[y-1][x]);
            if(child!=NULL)
                search(x,y-1,board,child,visited,result);
        }
        if(y<height-1 && !visited[(y+1)*width+x]){
            TrieNode *child=root->getChild(board[y+1][x]);
            if(child!=NULL)
                search(x,y+1,board,child,visited,result);
        }
        visited[y*width+x]=false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *tree=new Trie();
        int numWords=words.size();
        for(int i=0;i<numWords;i++)
            tree->insert(words[i]);
        
        vector<string> res;
        int height=board.size();
        int width=board[0].size();
        for(int i=0;i<width;i++)
            for(int j=0;j<height;j++){
                bool* visited=(bool*)malloc(sizeof(bool)*width*height);
                memset(visited,0,sizeof(bool)*width*height);
                TrieNode *child=tree->root->getChild(board[j][i]);
                if(child!=NULL)
                    search(i,j,board,child,visited,res);
                free(visited);
            }
        sort(res.begin(),res.end());
        auto it=res.begin();
        while(it!=res.end()){
            if(it!=res.begin() && *it==*(it-1))
                res.erase(it);
            else
                it++;
        }
        return res;
    }
};
