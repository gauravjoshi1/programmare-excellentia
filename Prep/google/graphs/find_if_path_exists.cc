// form a graph, do a dfs and it reaches the destination node
// then path exists
// time : O(n), space : O(n)

class Solution {
public:
    std::unordered_map<int, vector<int>> umap;
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for (int i = 0; i < edges.size(); i++) {
            umap[edges[i][0]].push_back(edges[i][1]);
            umap[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> visited(n, 0);
        dfs(umap, source, visited);
        return visited[destination];
    }

    void dfs(std::unordered_map<int, vector<int>>& umap, int src, vector<int>& visited) {
        if (visited[src]) return;
        visited[src] = true;
        for (int i = 0; i < umap[src].size(); i++) {
            dfs(umap, umap[src][i], visited);
        }
    }
};
