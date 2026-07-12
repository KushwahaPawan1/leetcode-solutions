class Solution {
public:

    // Normal Linked List Reverse Function
    ListNode* reverseList(ListNode* head) {

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* Next = NULL;

        // Jab tak list khatam na ho jaye
        while (curr) {

            // Next node save kar lo
            Next = curr->next;

            // Link reverse kar do
            curr->next = prev;

            // prev aur curr ko aage badhao
            prev = curr;
            curr = Next;
        }

        // Reverse list ka naya head return hoga
        return prev;
    }

    // Linked List ke left se right position tak reverse karega
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // Agar sirf ek hi node reverse karni hai
        if (left == right) return head;

        // a = left se pehle wali node
        // b = left wali node (reverse start)
        // c = right wali node (reverse end)
        // d = right ke baad wali node
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;

        ListNode* temp = head;
        int n = 1;

        // a, b, c, d pointers find karo
        while (temp) {

            if (n == left - 1)
                a = temp;

            if (n == left)
                b = temp;

            if (n == right)
                c = temp;

            if (n == right + 1)
                d = temp;

            temp = temp->next;
            n++;
        }

        // ---------------- List ko cut karo ----------------

        // Left part ko alag karo
        if (a != NULL)
            a->next = NULL;

        // Right part ko alag karo
        if (c)
            c->next = NULL;

        // ---------------- Middle Part Reverse ----------------

        ListNode* newHead = reverseList(b);

        // ---------------- Dubara Connect Karo ----------------

        // Agar left part exist karta hai
        if (a != NULL)
            a->next = newHead;

        // Reverse ke baad b last node ban jayegi
        // Usko right part se connect kar do
        b->next = d;

        // Agar reverse head se start hua tha
        if (a != NULL)
            return head;
        else
            return newHead;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {

        // temp har group ke starting node par rahega
        ListNode* temp = head;

        // Pehla group size = 1
        int gap = 1;

        while (temp && temp->next != NULL) {

            // Remaining group ki actual length nikalne ke liye
            int remLen = 0;

            // Group ki first node temp->next se start hogi
            ListNode* t = temp->next;

            // Maximum gap+1 nodes count karo
            for (int i = 1; i <= gap + 1 && t != NULL; i++) {
                t = t->next;
                remLen++;
            }

            // Agar last group expected size se chhota hai
            // To gap ko actual size ke hisaab se adjust kar do
            if (remLen < gap + 1)
                gap = remLen - 1;

            // Agar group ki length even hai
            // (gap odd hoga kyunki actual length = gap+1)
            if (gap % 2 != 0)
                reverseBetween(temp, 2, 2 + gap);

            // Agle group ka expected size badha do
            gap++;

            // temp ko next group ke start tak le jao
            for (int i = 1; temp != NULL && i <= gap; i++) {
                temp = temp->next;
            }
        }

        return head;
    }
};