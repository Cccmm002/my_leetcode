// In a 2D grid of 0s and 1s, we change at most one 0 to a 1.
//
// After, what is the size of the largest island? (An island is a 4-directionally connected group of 1s).
//
// Example 1:
//
//
// Input: [[1, 0], [0, 1]]
// Output: 3
// Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
//
//
// Example 2:
//
//
// Input: [[1, 1], [1, 0]]
// Output: 4
// Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 1.
//
// Example 3:
//
//
// Input: [[1, 1], [1, 1]]
// Output: 4
// Explanation: Can't change any 0 to 1, only one island with area = 1.
//
//  
//
// Notes:
//
//
// 	1 <= grid.length = grid[0].length <= 50.
// 	0 <= grid[i][j] <= 1.
//
//
//  


class Solution {
private:
    unordered_map<int, int> group;
    
    void bfs(vector<vector<int>> &grid, int col, int row, vector<vector<int>> &visited, int group_num) {
      int height = grid.size();
      int width = grid[0].size();
      queue<pair<int, int>> q;
      q.push(make_pair(row, col));
      group[group_num]++;
      visited[row][col] = group_num;
      while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for (int d = 0; d < 4; d++) {
          int new_col = c + dirs[d][0];
          int new_row = r + dirs[d][1];
          if (new_col < 0 || new_col >= width) continue;
          if (new_row < 0 || new_row >= height) continue;
          if (grid[new_row][new_col] != 1) continue;
          if (visited[new_row][new_col] >= 0) continue;
          group[group_num]++;
          visited[new_row][new_col] = group_num;
          q.push(make_pair(new_row, new_col));
        }
      }
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
          int height = grid.size();
          int width = grid[0].size();
          int current_group = 0;
          vector<vector<int>> visited(height, vector<int>(width, -1));
          for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
              if (grid[i][j] != 1) continue;
              if (visited[i][j] >= 0) continue;
              group[current_group] = 0;
              bfs(grid, j, i, visited, current_group);
              current_group++;
            }
          }
          int result = group.size() == 0 ? 0 : group[0];
          int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
          for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
              if (grid[i][j] != 0) continue;
              unordered_set<int> sur_groups;
              for (int d = 0;d < 4;d++) {
                int new_col = j + dirs[d][0];
                int new_row = i + dirs[d][1];
                if (new_col < 0 || new_col >= width) continue;
                if (new_row < 0 || new_row >= height) continue;
                if (grid[new_row][new_col] != 1) continue;
                sur_groups.insert(visited[new_row][new_col]);
              }
              int cur_sum = 0;
              auto it = sur_groups.begin();
              while (it != sur_groups.end()) {
                cur_sum += group[*it];
                it++;
              }
              result = max(result, cur_sum + 1);
            }
          }
          return result;
    }
};
