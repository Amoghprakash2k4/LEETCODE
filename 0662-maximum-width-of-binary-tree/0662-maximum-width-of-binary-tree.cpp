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
// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
        
//     }
// };
class Solution {
public:
    unsigned long long maxWidth = 0;
    
    void dfs(TreeNode* node, unsigned long long index, int depth, vector<unsigned long long>& leftMost) {
        if (!node) return;
        
        if (depth == leftMost.size()) {
            // First node at this depth
            leftMost.push_back(index);
        }
        
        // Compute width at this depth
        unsigned long long width = index - leftMost[depth] + 1;
        if (width > maxWidth) maxWidth = width;
        
        dfs(node->left, index * 2, depth + 1, leftMost);
        dfs(node->right, index * 2 + 1, depth + 1, leftMost);
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        vector<unsigned long long> leftMost; // Stores first index at each depth
        dfs(root, 1, 0, leftMost);
        return static_cast<int>(maxWidth);
    }
};
