// recursion : apply dfs from the point
// where you find '1' in the grid and keep
// marking them as zero for to avoid
// double counting.
//
// time : O(n), space : O(n)


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, m, n, i, j);
                }
            }
        }
        
        return islands;
    }

    void dfs(vector<vector<char>>& grid, int m, int n, int r, int c) {
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0') return;
        grid[r][c] = '0';
        dfs(grid, m, n, r + 1, c);
        dfs(grid, m, n, r - 1, c);
        dfs(grid, m, n, r, c + 1);
        dfs(grid, m, n, r, c - 1);
    }
};
