class Solution {
public:
    void reverse(ListNode* head, int times) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (times--) {
            ListNode* next = curr->next;  // Agle node ka address save karo

            curr->next = prev;  // Current node ka link ulta kar do

            prev = curr;  // Prev ko current node par le aao
            curr = next;  // Curr ko agle node par le aao
        }
    }

    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;  // List empty hai toh NULL return karo

        ListNode* left = head;  // Current pair ka pehla node
        ListNode* right;        // Current pair ka doosra node
        ListNode* res = NULL;   // Reversed list ka head store karega
        ListNode* prevLeft = NULL; // Previous reversed pair ka last node

        int size = 2;  // Har baar 2 nodes ko swap karna hai

        while (true) {
            right = left;  // Right ko current pair ke starting node par rakho

            // Left se right tak size-1 steps chalo
            // Isse right current pair ke doosre node par pahunch jayega
            for (int i = 0; i < size - 1; i++) {
                if (right == NULL)
                    break;  // Node nahi mila toh loop rok do

                right = right->next;
            }

            if (right) {
                // Agle pair ka starting node save karo,
                // kyunki reverse karne par links change ho jayenge
                ListNode* nextLeft = right->next;

                // Current pair ke 2 nodes ko reverse karo
                // Example: 1 -> 2 becomes 2 -> 1
                reverse(left, size);

                // Previous pair ke last node ko current pair ke
                // naye head (right) se connect karo
                if (prevLeft)
                    prevLeft->next = right;

                // Pehla pair reverse hone par right hi poori list ka head hoga
                if (res == NULL)
                    res = right;

                // Reverse hone ke baad left current pair ka last node hai
                // Ise previous pair ka last node bana do
                prevLeft = left;

                // Ab agle pair ko process karne ke liye aage badho
                left = nextLeft;
            }
            else {
                // Agar ek node bach gaya, toh use reverse nahi karna
                // Previous pair ke last node ko is node se connect karo
                if (prevLeft)
                    prevLeft->next = left;

                // Agar koi pair reverse nahi hua,
                // toh original head hi final head rahega
                if (res == NULL)
                    res = left;

                break;  // Saare pairs process ho gaye
            }
        }

        return res;  // Swapped linked list ka head return karo
    }
};