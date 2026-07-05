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
    ListNode* deleteMiddle(ListNode* head) {
        int n=0;
        ListNode* temp=head;
        if(head->next == NULL) return NULL; 
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int delIdx=n/2;//3
        temp=head;
        
        for(int i=1;i<=delIdx-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;

    }
};