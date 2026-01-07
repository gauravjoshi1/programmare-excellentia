// create a graph
// for each node apply bfs
// and have a 2d boolean array to
// maintain if the current node
// is reachable to other nodes
// or not.
//
// time : O(n^2), space : O(n)

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        std::vector<bool> res;
        std::vector<vector<bool>> is_reachable(numCourses, vector<bool>(numCourses, false));
        std::unordered_map<int, vector<int>> umap;
        for (auto pre : prerequisites) {
            umap[pre[0]].push_back(pre[1]);
        }

        std::queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            q.push(i);
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int nei : umap[curr]) {
                    if (!is_reachable[i][nei]) {
                        is_reachable[i][nei] = true;
                        q.push(nei);
                    }
                }
            }
        }

        for (auto que : queries) {
            res.push_back(is_reachable[que[0]][que[1]]);
        }
        return res;
    }
};
