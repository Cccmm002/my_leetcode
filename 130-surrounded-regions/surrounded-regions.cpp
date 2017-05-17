// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//
// A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
//
//
// For example,
//
// X X X X
// X O O X
// X X O X
// X O X X
//
//
//
//
// After running your function, the board should be:
//
// X X X X
// X X X X
// X X X X
// X O X X


class Solution {
public:
    struct point{
        int x,y;
        point(int xx,int yy) : x(xx),y(yy) {}
    };

    void solve(vector<vector<char>>& board) {
        if(board.size()<=0) return;
        int height=board.size();
        int width=board[0].size();  //board[row][col]
        bool *visited=(bool*)malloc(sizeof(bool)*height*width);
        memset(visited,0,sizeof(bool)*height*width);
        for(int i=0;i<height;i++)
            for(int j=0;j<width;j++){
                if(i<height-1 && i>0 && j<width-1 && j>0) continue;
                if(board[i][j]=='X') continue;
                queue<point> q;
                q.push(point(j,i));
                visited[i*width+j]=true;
                while(!q.empty()){
                    point p=q.front();
                    q.pop();
                    if(p.x!=0){
                        if(!visited[p.y*width+p.x-1] && board[p.y][p.x-1]!='X'){
                            visited[p.y*width+p.x-1]=true;
                            q.push(point(p.x-1,p.y));
                        }
                    }
                    if(p.y!=0){
                        if(!visited[(p.y-1)*width+p.x] && board[p.y-1][p.x]!='X'){
                            visited[(p.y-1)*width+p.x]=true;
                            q.push(point(p.x,p.y-1));
                        }
                    }
                    if(p.x!=width-1){
                        if(!visited[p.y*width+p.x+1] && board[p.y][p.x+1]!='X'){
                            visited[p.y*width+p.x+1]=true;
                            q.push(point(p.x+1,p.y));
                        }
                    }
                    if(p.y!=height-1){
                        if(!visited[(p.y+1)*width+p.x] && board[p.y+1][p.x]!='X'){
                            visited[(p.y+1)*width+p.x]=true;
                            q.push(point(p.x,p.y+1));
                        }
                    }
                }
            }
        
        for(int i=0;i<height;i++)
            for(int j=0;j<width;j++){
                if(board[i][j]!='X' && !visited[i*width+j])
                    board[i][j]='X';
            }
    }
};
