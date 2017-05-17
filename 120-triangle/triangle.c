// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
//
// For example, given the following triangle
//
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
//
//
//
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
//
//
// Note:
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.


int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    int vsize=triangleRowSize;
    int *s=(int*)malloc(sizeof(int)*vsize);
    s[0]=triangle[0][0];
    for(int i=1;i<vsize;i++)
        s[i]=INT_MAX;
    for(int i=1;i<vsize;i++) {
        int prev=INT_MAX;
        for(int j=0;j<=i;j++) {
            int cur=prev<s[j]?prev:s[j];
            prev=s[j];
            s[j]=cur+triangle[i][j];
        }
    }
    int mini=INT_MAX;
    for(int i=0;i<vsize;i++){
        if(mini>s[i])
            mini=s[i];
    }
    free(s);
    return mini;
}
