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
    // void dfs(TreeNode* node, vector<int>& arr){
    //     if (!node) return;
    //     dfs(node->left, arr);
    //     arr.push_back(node->val);
        
    //     dfs(node->right, arr);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
    //     // vector<int> arr;
    //     // dfs(root , arr);
    //     // return arr;
        
    // vector<int> result;
    // stack<TreeNode*> st;
    // TreeNode* curr = root;

    // while (curr != nullptr || !st.empty()) {
    //     // Go all the way left
    //     while (curr != nullptr) {
    //         st.push(curr);
    //         curr = curr->left;
    //     }

    //     // Process node
    //     curr = st.top();
    //     st.pop();
    //     result.push_back(curr->val);

    //     // Go to right subtree
    //     curr = curr->right;
    // }

    // return result;
    vector<int> result;
    TreeNode* current = root;

    while (current != nullptr) {
        if (current->left == nullptr) {
            // No left child: visit this node and move to right
            result.push_back(current->val);
            current = current->right;
        } else {
            // Has left child: find the inorder predecessor
            TreeNode* predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                // Create the thread to come back to current later
                predecessor->right = current;
                current = current->left;
            } else {
                // Thread already exists: remove it and visit current
                predecessor->right = nullptr;
                result.push_back(current->val);
                current = current->right;
            }
        }
    }
    return result;
}
};