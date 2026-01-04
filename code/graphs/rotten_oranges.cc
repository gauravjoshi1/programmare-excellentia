// use bfd store the cells
// with rotten oranges
//
// time : O(n^2), space : O(n^2)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int time = -1;
        vector<vector<int>> dir = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto curr = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int x = dir[i][0] + curr.first;
                    int y = dir[i][1] + curr.second;
                    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0 || grid[x][y] == 2) continue;
                    grid[x][y] = 2;
                    q.push({x, y});
                }
            }
            time++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return time == -1 ? 0 : time;
    }
};
