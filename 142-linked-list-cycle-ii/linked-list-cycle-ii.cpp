/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        bool flag=false; //false means no cycle
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) {
                flag=true;
                break;
            }
        }
        if(flag==false) return NULL;
        else{
            ListNode* temp=head;
            while(slow!=temp){
                slow=slow->next;
                temp=temp->next;
            }
            return temp;
        }
    }
};