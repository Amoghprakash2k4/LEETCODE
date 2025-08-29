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
    int diameterOfBinaryTree(TreeNode* root) {
    int maxd = 0;
    height(root, maxd);
    return maxd;
    }

    int height(TreeNode* node, int &maxd){
        if(!node) return 0;
        int left = height(node->left, maxd);
        int right = height(node->right, maxd);

        maxd = max(maxd, left+right);

        return 1 + max(left,right);
    }
};

