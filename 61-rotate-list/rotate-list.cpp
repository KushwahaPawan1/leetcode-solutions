class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // S-1: Edge cases handle karo
        // List empty hai ya sirf ek node hai toh rotate karne ki zaroorat nahi
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* last = head;
        int n = 1;

        // S-2: Total nodes count karo aur last node tak jao
        while(last->next != NULL) {
            n++;
            last = last->next;  // Last node par pahunch jao
        }

        // S-3: Agar k, nodes ki length se bada hai,
        // toh modulo se extra rotations remove kar do
        k = k % n;

        // Agar k = 0 hai, toh original list hi answer hai
        if(k == 0)
            return head;

        // S-4: New tail find karo
        // Right rotation mein last ke k nodes starting mein aayenge
        // Isliye new tail ki position = n-k
        ListNode* temp = head;

        for(int i = 1; i < n-k; i++) {
            temp = temp->next;
        }

        // S-5: New head, new tail ke next node par hoga
        // Example: 1 -> 2 -> 3 -> 4 -> 5
        // New tail = 3, new head = 4
        ListNode* newHead = temp->next;

        // S-6: New tail ka link NULL kar do
        // Ab first part ki list alag ho jayegi
        temp->next = NULL;

        // S-7: Original last node ko original head se connect karo
        // Isse last ke k nodes beginning mein aa jayenge
        ListNode* h = head;
        last->next = h;

        // S-8: Rotated list ka new head return karo
        return newHead;
    }
};