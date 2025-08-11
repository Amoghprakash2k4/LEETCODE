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

    int dfs(TreeNode* root, int maxsofar){
        if(!root) return 0;
        int count = 0;
        if(root->val >= maxsofar){
            count++;
            maxsofar=root->val;
        }
        count+=dfs(root->left,maxsofar);
        count+=dfs(root->right,maxsofar);

        return count;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
        
    }
};