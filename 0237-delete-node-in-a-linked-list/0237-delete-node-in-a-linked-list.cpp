/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;           // Copy next node's value
        ListNode* temp = node->next;           // Store next node temporarily
        node->next = node->next->next;         // Bypass the next node
        delete temp;                           // Delete the skipped node
    }
};
