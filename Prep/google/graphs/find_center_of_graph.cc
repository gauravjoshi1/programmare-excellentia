// first approach is to form a graph, and for each node check the number of edges
// emerging out from it is equal to number of nodes.

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        std::unordered_map<int, vector<int>> umap;
        for (int i = 0; i < edges.size(); i++) {
            umap[edges[i][0]].push_back(edges[i][1]);
            umap[edges[i][1]].push_back(edges[i][0]);
        }

        for (auto& [k, v] : umap) {
            if (v.size() == edges.size()) return k;
        }
        return -1;
    }
};


// as center will always exist, we can just check
// the first to edges and based on that return
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a = edges[0][0];
        int b = edges[0][1];
        int c = edges[1][0];
        int d = edges[1][1];
        return (a == c || b == c) ? c : d;
    }
};
