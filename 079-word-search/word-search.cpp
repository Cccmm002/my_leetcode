// Given a 2D board and a word, find if the word exists in the grid.
//
//
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
//
//
// For example,
// Given board = 
//
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
//
//
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.


class Solution {
private:
    bool find(int x, int y, vector<vector<char>>& board, string word, bool *visited){
        int len=word.length();
        if(len==0) return true;
        int height=board.size();
        int width=board[0].size();
        visited[y*width+x]=true;
        bool found=false;
        if(x>0 && board[y][x-1]==word[0] && !visited[y*width+x-1]){
            found=find(x-1,y,board,word.substr(1),visited);
            if(found) return true;
        }
        if(x<width-1 && board[y][x+1]==word[0] && !visited[y*width+x+1]){
            found=find(x+1,y,board,word.substr(1),visited);
            if(found) return true;
        }
        if(y>0 && board[y-1][x]==word[0] && !visited[(y-1)*width+x]){
            found=find(x,y-1,board,word.substr(1),visited);
            if(found) return true;
        }
        if(y<height-1 && board[y+1][x]==word[0] && !visited[(y+1)*width+x]){
            found=find(x,y+1,board,word.substr(1),visited);
            if(found) return true;
        }
        visited[y*width+x]=false;
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length()==0) return true;
        int height=board.size();
        int width=board[0].size();
        for(int i=0;i<height;i++)
            for(int j=0;j<width;j++){
                if(board[i][j]==word[0]){
                    bool *visited=(bool*)malloc(sizeof(bool)*width*height);  //visited[y*width+x]
                    memset(visited,0,sizeof(bool)*width*height);
                    bool res=find(j,i,board,word.substr(1),visited);
                    free(visited);
                    if(res) return true;
                }
            }
        return false;
    }
};
