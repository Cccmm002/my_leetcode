// There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
//
// The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.
//
// Note:
// All costs are positive integers.
//
// Example:
//
//
// Input: [[1,5,3],[2,9,4]]
// Output: 5
// Explanation: Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
//              Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5. 
//
//
// Follow up:
// Could you solve it in O(nk) runtime?
//


inline int findMin(int *arr, int exclude, int length) {
    int res = 2147483647;
    for (int i = 0; i < length; i++) {
        if (i == exclude) continue;
        res = arr[i] < res ? arr[i] : res;
    }
    return res;
}

int minCostII(int** costs, int costsRowSize, int costsColSize) {
    if (costsRowSize <= 0) return 0;
    int *current = (int*)malloc(sizeof(int)*costsColSize);
    for (int i = 0; i < costsColSize; i++) current[i] = costs[0][i];
    for (int i = 1; i < costsRowSize; i++) {
        int *n = (int*)malloc(sizeof(int)*costsColSize);
        for (int j = 0; j < costsColSize; j++) n[j] = findMin(current, j, costsColSize) + costs[i][j];
        for (int j = 0; j < costsColSize; j++) current[j] = n[j];
        free(n);
    }
    int res = findMin(current, -1, costsColSize);
    free(current);
    return res;
}
