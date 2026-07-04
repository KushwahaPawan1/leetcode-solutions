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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr=list1;
        ListNode* prev=list1;
       for(int i=0;i<=a-1;i++){//2
        prev=curr;
        curr=curr->next;
       }
       prev->next=list2;//13 ko 100000 se connect kr dia
       ListNode* temp2=list2;
       while(temp2->next!=NULL){
        temp2=temp2->next;
       }
       ListNode* tail2=temp2;
       for(int i=a;i<=b;i++){//2 se 5
        curr=curr->next;
       }
       tail2->next=curr;
       return list1;

    }
};