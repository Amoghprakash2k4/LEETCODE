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
    int maxSum = INT_MIN; // to track global maximum

    int maxGain(TreeNode* node) {
        if (!node) return 0;

        // Recursively compute the max gain from left and right
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        // If we split at this node, this is the path sum
        int priceNewPath = node->val + leftGain + rightGain;

        // Update the global maximum if needed
        maxSum = max(maxSum, priceNewPath);

        // Return max gain to parent (must pick one side)
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};
