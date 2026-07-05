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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        if(k==0) return head; // k=0 means as it is link list bhejo
        ListNode* h=head;
        ListNode* temp=head;
        ListNode* tail=head;
        int count =1;
        while(tail->next!=NULL){
            count++;
            tail=tail->next;
        }
        if(k>=count) k=k%count;
        if(k==0) return head; // k=0 means as it is link list bhejo
        //temp ko k-1 par rakho
        for(int i=1; i<=count-k-1; i++){//2
         temp=temp->next;
        }
        //5 ko 1 se connect kro
        tail->next=h;
        //head abhi 1 pe h...head ko 4 pe lao i.e temp k next pe
        h=temp->next;
        //temp 3 pe tha ab usse null se attach kro cuz vo last node h 
        temp->next=NULL;
        return h;
    }
};