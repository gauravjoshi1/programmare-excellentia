// approach : find the start of island
// that is any index which is 1, call
// dfs recursively with visited array,
// increment perimeter if any end is
// reached that is either boundary or
// already visited node, but don't
// increment if it is visited, only
// return if the node is visited.
//
// time : O(n), space : O(n)


class Solution {
public:
    vector<vector<int>> dir;
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int island_perimeter = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, m, n, vis, island_perimeter);
                    break;
                }
            }
        }
        return island_perimeter;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int m, int n, vector<vector<bool>>& vis, int& perimeter) {
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0) {
            perimeter++;
            return;
        }
        if (vis[r][c]) return;
        vis[r][c] = true;
        for (int i = 0; i < 4; i++) {
            dfs(grid, dir[i][0] + r, dir[i][1] + c, m, n, vis, perimeter);
        }

    }
};
