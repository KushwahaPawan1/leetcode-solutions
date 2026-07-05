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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        while(curr!=NULL  && curr->next != NULL){
            // same h value
            if(curr->val==curr->next->val){
                curr->next=curr->next->next;
            }
            else{
                //diff h value to curr ko aage badhao
                curr=curr->next; 
            }
        }
        return head;
        
    }
};