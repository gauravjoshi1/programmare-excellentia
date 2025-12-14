class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num_islands = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    num_islands++;
                    dfs(grid, m, n, i, j);
                }
            }
        }
        return num_islands;
    }

    void dfs(vector<vector<char>>& grid, int m, int n, int r, int c) {
        if (r >= m || c >= n || r < 0 || c < 0 || grid[r][c] == '0') return;
        grid[r][c] = '0';
        dfs(grid, m, n, r + 1, c);
        dfs(grid, m, n, r - 1, c);
        dfs(grid, m, n, r, c + 1);
        dfs(grid, m, n, r, c - 1);
    }
};
