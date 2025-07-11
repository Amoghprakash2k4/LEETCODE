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
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         vector<int> values;

//         // Step 1: Collect all values from the lists
//         for (auto list : lists) {
//             while (list) {
//                 values.push_back(list->val);
//                 list = list->next;
//             }
//         }

//         // Step 2: Sort all values
//         sort(values.begin(), values.end());

//         // Step 3: Build a new sorted linked list
//         ListNode* dummy = new ListNode(0);
//         ListNode* current = dummy;

//         for (int val : values) {
//             current->next = new ListNode(val);
//             current = current->next;
//         }

//         return dummy->next;
//     }
// };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Custom comparator for min-heap
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap
        };
        
        // Min-heap with ListNode* elements
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
        
        // Initialize the heap with the head of each list
        for (auto node : lists) {
            if (node) {
                minHeap.push(node);
            }
        }
        
        // Dummy node to build the result list
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            tail->next = smallest;
            tail = tail->next;
            
            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }
        
        return dummy.next;
    }
};

