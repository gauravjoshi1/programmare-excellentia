// recursion : traverse only the cells
// with 1 in it , and replace the cells
// with 0 after visiting, increment
// the area var for each one.
// keep track of max area island
//
// time : O(n^2) space : O(n)

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int area = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    area = 0;
                    dfs(grid, i, j, m, n, area);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int m, int n, int& area) {
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0) return;
        area++;
        grid[r][c] = 0;
        dfs(grid, r + 1, c, m, n, area);
        dfs(grid, r - 1, c, m, n, area);
        dfs(grid, r, c + 1, m, n, area);
        dfs(grid, r, c - 1, m, n, area);
    }
};
