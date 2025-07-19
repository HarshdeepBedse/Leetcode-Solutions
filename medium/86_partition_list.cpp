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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = nullptr;  // List for values less than x
        ListNode* right = nullptr;  // List for values greater or equal to x
        ListNode* leftTail = nullptr;  // Tail of left list
        ListNode* rightTail = nullptr;  // Tail of right list
        
        while (head != nullptr) {
            if (head->val < x) {
                // Insert node in the left list
                if (left == nullptr) {
                    left = head;
                    leftTail = left;
                } else {
                    leftTail->next = head;
                    leftTail = leftTail->next;
                }
            } else {
                // Insert node in the right list
                if (right == nullptr) {
                    right = head;
                    rightTail = right;
                } else {
                    rightTail->next = head;
                    rightTail = rightTail->next;
                }
            }
            head = head->next;
        }
        
        // Avoid circular references
        if (rightTail != nullptr) {
            rightTail->next = nullptr;
        }
        
        // Combine left and right lists
        if (left == nullptr) {
            return right;  // If there are no nodes < x, return right list
        }
        
        leftTail->next = right;  // Connect left list to right list
        return left;  // Return the head of the left list
    }
};