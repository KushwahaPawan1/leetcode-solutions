class Solution {
public:
  ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* Next=NULL;
        while(curr){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;

    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        //slow is at left middle
        ListNode* b= reverseList(slow->next);
        ListNode* a=head;
        slow->next=NULL;//for breaking list
        //merge these two a and b alternatively
        ListNode* c=new ListNode(-1);// c is farzi node 
        ListNode* tempC=c;
        ListNode* tempA=a;
        ListNode* tempB=b;
        while(tempA!=NULL && tempB!=NULL){
            tempC->next=tempA;
            tempA=tempA->next;
            tempC=tempC->next;

            tempC->next=tempB;
            tempB=tempB->next;
            tempC=tempC->next;
        }
        tempC->next=tempA;
        head=c->next;

    }
};