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
    ListNode* removeElements(ListNode* head, int val) {

        // ListNode* curr = head;
        // ListNode* prev = head;

        // Head case
        while (head != NULL && head->val == val) {
            head = head->next;
        }

        if (head == NULL) {
            return NULL;
        }
 
        ListNode* curr = head;
        ListNode* prev = head;

        while (curr != NULL) {
            if (curr->val == val) {
                // curr == val, delete current node
                prev->next = curr->next;   // 2 ko 3 se connect
                curr = curr->next;  // curr ko next node par le jao
            }
            else {
                // curr != val, dono pointers move karo
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};