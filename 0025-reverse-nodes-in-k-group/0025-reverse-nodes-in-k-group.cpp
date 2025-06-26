class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node to simplify edge cases
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroupEnd = &dummy;

        while (true) {
            // Check if we have at least k nodes left
            ListNode* kth = prevGroupEnd;
            for (int i = 0; i < k && kth; ++i) {
                kth = kth->next;
            }
            if (!kth) break;

            ListNode* groupStart = prevGroupEnd->next;
            ListNode* curr = groupStart;
            ListNode* prev = kth->next;
            ListNode* next = nullptr;

            // Reverse k nodes
            for (int i = 0; i < k; ++i) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            prevGroupEnd->next = prev;
            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};
