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

    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* tempA=a;
        ListNode* tempB=b;
        ListNode* c=new ListNode(-1);
        ListNode* tempC=c;
        while(tempA!=NULL && tempB!=NULL){
            if(tempA->val<=tempB->val) {
                ListNode* t=new ListNode(tempA->val);
                tempC->next=t;
                tempC=t;
                tempA=tempA->next;

            }
            else{
                 ListNode* t=new ListNode(tempB->val);
                 tempC->next=t;
                 tempC=t;
                 tempB=tempB->next;
            }
        }
        //jab ek list khtm doosri list ke bache hue elements direct use kro
        if(tempA==NULL){
            tempC->next=tempB;
        }
        else{//tempB==NULL
            tempC->next=tempA;
        }
        return c->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size()==0) return NULL;
        while(arr.size()>1){
            ListNode* a=arr[0];
            arr.erase(arr.begin());//aage se delete hoga element
            ListNode* b=arr[0];
            arr.erase(arr.begin());
            ListNode* c =merge(a,b);
            arr.push_back(c);
        }
        return arr[0];
    }
};