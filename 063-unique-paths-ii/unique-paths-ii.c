// Follow up for "Unique Paths":
//
// Now consider if some obstacles are added to the grids. How many unique paths would there be?
//
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
// For example,
// There is one obstacle in the middle of a 3x3 grid as illustrated below.
//
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
//
// The total number of unique paths is 2.
//
// Note: m and n will be at most 100.


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
