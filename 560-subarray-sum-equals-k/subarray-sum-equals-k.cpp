class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();

        // Step 1: Prefix sum array banao
        // pre[i] = arr[0] + arr[1] + ... + arr[i]
        vector<int> pre(n, 0);

        pre[0] = arr[0];

        for (int i = 1; i < n; i++) {
            pre[i] = arr[i] + pre[i - 1];
        }

        // Map mein prefix sum ki frequency store karenge
        unordered_map<int, int> m;

        int count = 0;

        for (int i = 0; i < n; i++) {

            // Agar current prefix sum k ke equal hai,
            // to index 0 se i tak ka subarray ka sum k hai
            if (pre[i] == k) {
                count++;
            }

            // Hume previous prefix sum chahiye:
            // currentSum - previousSum = k
            // previousSum = currentSum - k
            int rem = pre[i] - k;

            // Agar ye previous prefix sum pehle mila hai,
            // to utne valid subarrays banenge
            if (m.find(rem) != m.end()) {
                count += m[rem];
            }

            // Current prefix sum ko map mein store karo
            // Agar same prefix sum dobara aata hai,
            // to uski frequency increase hogi
            m[pre[i]]++;
        }

        return count;
    }
};