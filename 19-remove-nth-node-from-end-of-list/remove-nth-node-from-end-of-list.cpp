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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //cal len
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }

        if(n==len) { //first node delete krna h 
            head=head->next;
            return head;
        }
        int delNth=len-n+1;//5-2+1=4
        temp=head;
        for(int i=1;i<=delNth-2;i++){ //2
            temp=temp->next;
        }
        
            temp->next=temp->next->next; // 3 connect hua 5 se
            return head;
        
    }
};