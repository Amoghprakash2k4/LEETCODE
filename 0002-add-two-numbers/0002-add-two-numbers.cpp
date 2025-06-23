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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* prev = nullptr;
        int carry = 0;

        while (l1 || l2) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
            }

            if (l2) {
                sum += l2->val;
            }

            carry = sum / 10;
            sum = sum % 10;

            if (l1) {
                l1->val = sum;
                prev = l1;
                l1 = l1->next;
            } else {
                // If l1 is shorter, add new node at end
                prev->next = new ListNode(sum);
                prev = prev->next;
            }

            if (l2) {
                l2 = l2->next;
            }
        }

        // Handle final carry
        if (carry) {
            prev->next = new ListNode(carry);
        }

        return head;
    }
};
