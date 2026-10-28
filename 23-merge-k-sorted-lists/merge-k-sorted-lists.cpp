class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        // S-1: Har list ka first node heap me daalo
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        // S-2: Dummy node banao
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        // S-3: Heap empty hone tak process karo
        while (!pq.empty()) {

            // Sabse chhota node nikalo
            ListNode* node = pq.top();
            pq.pop();

            // Answer list me jodo
            tail->next = node;
            tail = tail->next;

            // Usi list ka next node heap me daalo
            if (node->next != NULL) {
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};