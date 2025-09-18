/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        if (!root) return result;

        // Step 1: Build parent map
        unordered_map<TreeNode*, TreeNode*> parent;
        buildParentMap(root, nullptr, parent);

        // Step 2: BFS from target node
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);

        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            if (dist == k) {
                // collect all nodes at distance k
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                // explore neighbors: left, right, parent
                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (parent[node] && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
            dist++;
        }

        return result;
    }

private:
    void buildParentMap(TreeNode* node, TreeNode* par,
                        unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!node) return;
        parent[node] = par;
        buildParentMap(node->left, node, parent);
        buildParentMap(node->right, node, parent);
    }
};
