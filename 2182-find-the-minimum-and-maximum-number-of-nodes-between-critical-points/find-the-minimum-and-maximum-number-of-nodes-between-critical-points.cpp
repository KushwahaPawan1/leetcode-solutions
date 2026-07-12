class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        // idx = current (middle) node ka index
        int idx = 1;

        // firstCritical = pehle critical point ka index
        // lastCritical = latest critical point ka index
        int firstCritical = -1;
        int lastCritical = -1;

        // 3 pointers taaki previous, current aur next node compare kar saken
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next->next;

        // Agar 3 nodes hi nahi hain to critical point possible hi nahi
        if (c == NULL) return {-1, -1};

        // ---------------- First Traversal ----------------
        // Is traversal me first aur last critical point ka index nikalenge
        while (c) {

            // Check karo ki current node local maxima ya local minima hai ya nahi
            if ((b->val > a->val && b->val > c->val) ||
                (b->val < a->val && b->val < c->val)) {

                // Agar pehla critical point hai
                if (firstCritical == -1)
                    firstCritical = idx;

                // Warna latest critical point update kar do
                else
                    lastCritical = idx;
            }

            // Teeno pointers ko ek step aage badhao
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }

        // Agar sirf ek ya zero critical point mila ho vo firstcritical me update hoga means lastcritical abhi bhi -1 hoga
        if (lastCritical == -1) return {-1, -1};

        // Maximum distance = first aur last critical point ke beech ka distance
        int maximumDistance = lastCritical - firstCritical;

        // Minimum distance ko initially bahut bada maan lo
        int minimumDistance = INT_MAX;

        // Second traversal ke liye sab reset kar do
        firstCritical = -1;
        lastCritical = -1;
        idx = 1;

        a = head;
        b = head->next;
        c = head->next->next;

        // ---------------- Second Traversal ----------------
        // Is traversal me consecutive critical points ke beech minimum distance nikalenge
        while (c) {

            if ((b->val > a->val && b->val > c->val) ||
                (b->val < a->val && b->val < c->val)) {

                // Previous critical point ka index save karo
                firstCritical = lastCritical;

                // Current critical point latest ban gaya
                lastCritical = idx;

                // Agar previous critical point exist karta hai
                if (firstCritical != -1) {

                    // Consecutive critical points ke beech ka distance
                    int currentDistance = lastCritical - firstCritical;

                    // Minimum distance update karo
                    minimumDistance = min(minimumDistance, currentDistance);
                }
            }

            // Teeno pointers ko ek step aage badhao
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }

        // {minimumDistance, maximumDistance} return karo
        return {minimumDistance, maximumDistance};
    }
};