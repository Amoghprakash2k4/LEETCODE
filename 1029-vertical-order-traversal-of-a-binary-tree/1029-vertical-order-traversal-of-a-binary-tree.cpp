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
    map<int, map<int, multiset<int>>> nodes;

    void dfs(TreeNode* node, int x, int y) {
        if (!node) return;

        nodes[x][y].insert(node->val);

        dfs(node->left, x - 1, y + 1);
        dfs(node->right, x + 1, y + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);

        vector<vector<int>> result;

        for (auto& [col, mp] : nodes) {
            vector<int> column;
            for (auto& [row, s] : mp) {
                column.insert(column.end(), s.begin(), s.end());
            }
            result.push_back(column);
        }

        return result;
    }
};
