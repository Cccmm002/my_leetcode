// Given several boxes with different colors represented by different positive numbers. 
// You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1), remove them and get k*k points.
// Find the maximum points you can get.
//
//
// Example 1:
// Input: 
//
// [1, 3, 2, 2, 2, 3, 4, 3, 1]
//
// Output:
//
// 23
//
// Explanation: 
//
// [1, 3, 2, 2, 2, 3, 4, 3, 1] 
// ----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
// ----> [1, 3, 3, 3, 1] (1*1=1 points) 
// ----> [1, 1] (3*3=9 points) 
// ----> [] (2*2=4 points)
//
//
//
// Note:
// The number of boxes n would not exceed 100.
//
//


public class Solution {
    private int calc(int i, int j ,int k, int[,,] arr, int[] boxes) {
        if (i > j) return 0;
        if (i == j) return (k + 1) * (k + 1);
        if (arr[i,j,k] >= 0) return arr[i,j,k];
        while (i < j && boxes[i] == boxes[i + 1]) {
            i++;
            k++;
        }
        int res = (k + 1) * (k + 1) + calc(i + 1, j, 0, arr, boxes);
        for (int m = i + 1; m <= j; m++) {
            if (boxes[i] != boxes[m]) continue;
            int cur = calc(i + 1, m - 1, 0, arr, boxes) + calc(m, j, k + 1, arr, boxes);
            res = Math.Max(res, cur);
        }
        arr[i,j,k] = res;
        return res;
    }
    
    public int RemoveBoxes(int[] boxes) {
        int n = boxes.Length;
        if (n == 0) return 0;
        int[,,] arr = new int[n, n, n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) arr[i,j,k] = -1;
            }
        }
        int res = calc(0, n - 1, 0, arr, boxes);
        return res;
    }
}
