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
    bool dfs(TreeNode* node, unordered_set<int>& seen, int k){
        if(!node) return false;
        if(seen.count(k-node->val)) return true;
        seen.insert(node->val);
        return dfs(node->left, seen, k) || dfs(node->right, seen, k);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return dfs(root, seen ,k);
    }
};