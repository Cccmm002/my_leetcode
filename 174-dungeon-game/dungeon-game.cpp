// table.dungeon, .dungeon th, .dungeon td {
//   border:3px solid black;
// }
//
//  .dungeon th, .dungeon td {
//     text-align: center;
//     height: 70px;
//     width: 70px;
// }
//
// The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.
//
// The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
//
// Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
//
// In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
//
//  
//
// Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
//
// For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
//
//
//
//
// 			-2 (K)
// 			-3
// 			3
//
//
// 			-5
// 			-10
// 			1
//
//
// 			10
// 			30
// 			-5 (P)
//
//
//
//
//  
//
// Note:
//
//
// 	The knight's health has no upper bound.
// 	Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
//
//


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if(m == 0) return 1;
        int n = dungeon[0].size();
        int **v = new int*[m+1];
        for(int i=0;i<=m;i++)
            v[i] = new int[n+1];
        v[m-1][n-1] = dungeon[m-1][n-1]>=0 ? 1 : (1-dungeon[m-1][n-1]);
        for(int i = 0;i<m;i++)
            v[i][n] = INT_MAX;
        for(int i=0;i<n;i++)
            v[m][i] = INT_MAX;
        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                if(i==m-1 && j==n-1) continue;
                int cur = dungeon[i][j];
                int mini = v[i+1][j] < v[i][j+1] ? v[i+1][j] : v[i][j+1];
                if(cur<0) {
                    v[i][j] = mini - cur;
                }
                else {
                    if(cur + 1 >= mini) {
                        v[i][j] = 1;
                    }
                    else {
                        v[i][j] = mini - cur;
                    }
                }
            }
        }
        return v[0][0];
    }
};
