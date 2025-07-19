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
    ListNode* findmid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if (list1) {
            temp->next = list1;
        }
        if (list2) {
            temp->next = list2;
        }
        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* mid = findmid(head);
        ListNode* list1 = head;
        ListNode* list2 = mid->next;
        mid->next = nullptr;

        list1 = sortList(list1);
        list2 = sortList(list2);
        ListNode* answer = merge(list1, list2);
        return answer;
    }
};