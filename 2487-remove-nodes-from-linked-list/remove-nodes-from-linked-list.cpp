class Solution {
public:
    ListNode* removeNodes(ListNode* head) {

        stack<ListNode*> st;

        ListNode* temp = head;

        while (temp != NULL) {

            // Agar current node bada hai,
            // to stack ke chhote nodes remove karo
            while (!st.empty() && st.top()->val < temp->val) {
                st.pop();
            }

            // Current node ko stack me daalo
            st.push(temp);

            temp = temp->next;
        }

        // Stack me bache nodes ko reverse order me
        // linked list ke form me connect karenge

        ListNode* next = NULL;

        while (!st.empty()) {
            st.top()->next = next;
            next = st.top();
            st.pop();
        }

        return next;
    }
};