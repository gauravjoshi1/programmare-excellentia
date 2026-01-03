// approach : use dfs to create
// new node, along with neighbors
// hash map to keep track of the
// new nodes created
//
// bfs can also be used
//
// time : O(n), space :O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        std::unordered_map<Node*, Node*> umap;
        return clone(node, umap);
    }

    Node* clone(Node* node, std::unordered_map<Node*, Node*>& umap) {
        if (!node) return node;
        if (umap.count(node)) return umap[node];
        umap[node] = new Node(node->val);
        for (Node* nei : node->neighbors) {
            umap[node]->neighbors.push_back(clone(nei, umap));
        }
        return umap[node];
    }
};
