// approach : using topological
// sort.
//
// time : O(n), space : O(n)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::queue<int> q;
        std::vector<int> in(numCourses, 0);
        std::unordered_map<int, vector<int>> umap;
    
        for (vector<int>& pre : prerequisites) {
            umap[pre[1]].push_back(pre[0]);
            in[pre[0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int nei : umap[curr]) {
                in[nei]--;
                if (in[nei] == 0) q.push(nei);
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (in[i] != 0) return false;
        }
        return true;
    }
};
