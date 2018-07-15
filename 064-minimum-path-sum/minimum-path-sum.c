// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.
//
// Example:
//
//
// Input:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
// Explanation: Because the path 1→3→1→1→1 minimizes the sum.
//
//


int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int *s=(int*)malloc(sizeof(int)*gridRowSize*gridColSize);
    s[0]=grid[0][0];
    for(int y=0;y<gridRowSize;y++){
        for(int x=0;x<gridColSize;x++){
            if(x==0&&y==0) continue;
            if(y==0){
                s[y*gridColSize+x]=grid[y][x]+s[y*gridColSize+x-1];
                continue;
            }
            if(y==0){
                s[y*gridColSize+x]=grid[y][x]+s[(y-1)*gridColSize+x];
                continue;
            }
            s[y*gridColSize+x]=s[y*gridColSize+x-1]<s[(y-1)*gridColSize+x]?s[y*gridColSize+x-1]:s[(y-1)*gridColSize+x];
            s[y*gridColSize+x]+=grid[y][x];
        }
    }
    int res=s[gridRowSize*gridColSize-1];
    free(s);
    return res;
}
