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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* finder = head;
        int length=0;
        while(finder != nullptr){
            length++;
            finder = finder->next;
        }
        if (n == length) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        int target = length - n ; 
        int count = 1;
        ListNode* curr= head;
        ListNode* prev = nullptr;
        ListNode* next1 = curr->next;
        while(count <= target){
            // ListNode* next1 = curr->next;
            prev = curr;
            curr = next1;
            next1 = next1->next;
            count++;
        }
        prev->next = next1;
        curr->next = nullptr;
        return head;
    }
    
};