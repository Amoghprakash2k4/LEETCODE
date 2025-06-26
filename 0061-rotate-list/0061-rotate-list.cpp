/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* dummy = head;
        int count = 1;
        while(dummy->next){
            dummy = dummy->next;
            count++;
        }
        dummy->next = head;
        dummy = dummy->next;
        k = k%count;
        int stepsToNewTail = count - k;

        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;


    }
};