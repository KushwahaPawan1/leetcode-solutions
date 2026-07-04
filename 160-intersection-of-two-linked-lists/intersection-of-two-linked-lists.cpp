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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0;
        int lenB=0;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        while(tempA!=NULL){
            lenA++;
            tempA=tempA->next;
        }

        while(tempB!=NULL){
            lenB++;
            tempB=tempB->next;
        }
        //ab fir se tempA aur tempB ko head pe lao
         tempA=headA;
         tempB=headB;
        int diff = abs(lenA - lenB); //2
        if(lenA>lenB){
            for(int i=1;i<=diff;i++){
                tempA=tempA->next; //temp++
            }
            //tempB=headB;
        }
        else{ //lenB>lenA
           for(int i=1;i<=diff;i++){
              tempB=tempB->next;
            }
            //tempA=headA;
        }
        //ab adress compare
        while(tempA!=tempB){
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;

    }
};