// There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
//
//
// The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.
//
//
// Note:
// All costs are positive integers.


inline int min(int a, int b) {
    return a < b ? a : b;
}

int minCost(int** costs, int costsRowSize, int costsColSize) {
    if (costsRowSize <= 0) return 0;
    int red = costs[0][0];
    int blue = costs[0][1];
    int green = costs[0][2];
    for (int i = 1; i < costsRowSize; i++) {
        int nr = min(blue, green) + costs[i][0];
        int nb = min(red, green) + costs[i][1];
        int ng = min(red, blue) + costs[i][2];
        red = nr;
        green = ng;
        blue = nb;
    }
    return min(red, min(blue, green));
}
