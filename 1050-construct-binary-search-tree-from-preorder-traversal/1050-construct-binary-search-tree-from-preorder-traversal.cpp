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
    int i = 0;
    
    TreeNode* build(vector<int>& preorder, int lower, int upper) {
        if (i == preorder.size())
            return nullptr;
        
        int val = preorder[i];
        if (val < lower || val > upper)
            return nullptr;
        
        i++;
        TreeNode* node = new TreeNode(val);
        node->left = build(preorder, lower, val);
        node->right = build(preorder, val, upper);
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MIN, INT_MAX);
    }
};
