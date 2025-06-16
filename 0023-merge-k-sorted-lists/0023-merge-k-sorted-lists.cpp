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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;

        // Step 1: Collect all values from the lists
        for (auto list : lists) {
            while (list) {
                values.push_back(list->val);
                list = list->next;
            }
        }

        // Step 2: Sort all values
        sort(values.begin(), values.end());

        // Step 3: Build a new sorted linked list
        ListNode* dummy = new ListNode;
        ListNode* current = dummy;

        for (int val : values) {
            current->next = new ListNode(val);
            current = current->next;
        }

        return dummy->next;
    }
};
