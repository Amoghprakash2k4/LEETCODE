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
//     int count = 0;
//     int result = -1;

//     void inorder(TreeNode* node, int k) {
//         if (!node) return;
//         inorder(node->left, k);
//         count++;
//         if (count == k) {
//             result = node->val;
//             return;
//         }
//         inorder(node->right, k);
//     }

//     int kthSmallest(TreeNode* root, int k) {
//         inorder(root, k);
//         return result;
//     }
// };

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        inorder(root, result);
        return result[k-1];
    }

    void inorder(TreeNode* root, vector<int>& result){
        if(!root) return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
};
