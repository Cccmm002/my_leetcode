// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
// Now consider if some obstacles are added to the grids. How many unique paths would there be?
//
//
//
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
// Note: m and n will be at most 100.
//
// Example 1:
//
//
// Input:
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// Output: 2
// Explanation:
// There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right
//
//


int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int m=obstacleGridRowSize;
    int n=obstacleGridColSize;
    int *arr=(int*)malloc(sizeof(int)*m*n);
    arr[0]=obstacleGrid[0][0]==1?0:1;
    for(int y=0;y<m;y++){
        for(int x=0;x<n;x++){
            if(obstacleGrid[y][x]==1){
                arr[y*n+x]=0;
                continue;
            }
            if(x==0&&y==0) continue;
            if(y==0){
                arr[y*n+x]=arr[y*n+x-1];
                continue;
            }
            if(x==0){
                arr[y*n+x]=arr[(y-1)*n+x];
                continue;
            }
            arr[y*n+x]=arr[(y-1)*n+x]+arr[y*n+x-1];
        }
    }
    int res=arr[m*n-1];
    free(arr);
    return res;
}
