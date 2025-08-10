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
    int dfs(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(dfs(node->left), dfs(node->right));
    }

    void printlevel(TreeNode* node, int level, vector<int>& current) {
        if (!node) return;
        if (level == 1) {
            current.push_back(node->val);
        } else {
            printlevel(node->left, level - 1, current);
            printlevel(node->right, level - 1, current);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        int height = dfs(root);
        for (int i = 1; i <= height; i++) {
            vector<int> current;
            printlevel(root, i, current);
            result.push_back(current);
        }
        return result;
    }
};

