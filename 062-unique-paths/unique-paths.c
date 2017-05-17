// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
// How many possible unique paths are there?
//
//
//
// Above is a 3 x 7 grid. How many possible unique paths are there?
//
//
// Note: m and n will be at most 100.


int uniquePaths(int m, int n) {
    int *arr=(int*)malloc(sizeof(int)*m*n);
    for(int y=0;y<m;y++){
        for(int x=0;x<n;x++){
            if(y==0||x==0){
                arr[y*n+x]=1;
                continue;
            }
            arr[y*n+x]=arr[(y-1)*n+x]+arr[y*n+x-1];
        }
    }
    int res=arr[m*n-1];
    free(arr);
    return res;
}
