/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to add two numbers represented by linked lists
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = createNode(0);  // Dummy node to simplify code
    struct ListNode* current = dummyHead;        // Pointer to build the result list
    int carry = 0;                               // To store carry value

    // Loop until both lists are exhausted or there is a carry
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int val1 = (l1 != NULL) ? l1->val : 0;   // Get the value from l1, or 0 if NULL
        int val2 = (l2 != NULL) ? l2->val : 0;   // Get the value from l2, or 0 if NULL
        int sum = val1 + val2 + carry;           // Calculate the sum of both digits and carry

        carry = sum / 10;                        // Update carry
        current->next = createNode(sum % 10);    // Create a new node with the digit

        current = current->next;                 // Move to the next node

        // Move to the next nodes in l1 and l2 if they exist
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    struct ListNode* result = dummyHead->next;   // Result is next to the dummy node
    free(dummyHead);                             // Free the dummy node
    return result;                               // Return the result list
}

// Helper function to print a linked list
void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}
