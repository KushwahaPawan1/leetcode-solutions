class Solution {
public:
    // K nodes ko reverse karne ka function
    void reverse(ListNode* left, int size) {
        ListNode* curr = left;
        ListNode* prev = NULL;

        while (size--) {
            ListNode* next = curr->next; // Agle node ka address save karo

            curr->next = prev; // Current node ka link reverse karo

            prev = curr; // Prev ko current node par lao
            curr = next; // Curr ko agle node par le jao
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) {
            return head;
        }
        else {
            ListNode* left = head;
            ListNode* right;
            ListNode* prevLeft = NULL;
            ListNode* res = NULL;

            while (left ) {
                right = left;

                // Check karo ki current group mein k nodes hain ya nahi
                for (int i = 0; i < k - 1; i++) {
                    if (right == NULL) {
                        break;
                    }
                    else {
                        right = right->next;
                    }
                }

                // Agar complete group nahi mila
                if (right == NULL) {
                    // Previous group ko remaining nodes se connect karo
                    if (prevLeft) {
                        prevLeft->next = left;
                    }
                    else {
                        // Abhi tak koi group reverse nahi hua
                        if (res == NULL) {
                            res = left;
                        }
                    }

                    break;
                }
                else {
                    // Agle group ka starting node save karo
                    ListNode* nextLeft = right->next;

                    // Current group ke k nodes reverse karo
                    reverse(left, k);

                    // Previous group ko current reversed group se connect karo
                    if (prevLeft) {
                        prevLeft->next = right;
                    }
                    else {
                        // Pehle reversed group ka head set karo
                        if (res == NULL) {
                            res = right;
                        }
                    }

                    // Current group ka last node save karo
                    prevLeft = left;

                    // Agle group par move karo
                    left = nextLeft;
                }
            }

            return res;
        }
    }
};