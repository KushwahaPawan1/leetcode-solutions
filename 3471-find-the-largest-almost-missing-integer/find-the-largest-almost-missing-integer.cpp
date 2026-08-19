class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Case 1: k = 1 → find max element with frequency exactly 1
        if (k == 1) {
            unordered_map<int,int> freq;
            for (int x : nums) freq[x]++;
            int ans = -1;
            for (auto& [val, cnt] : freq)
                if (cnt == 1) ans = max(ans, val);
            return ans;
        }

        // Case 2: k = n → whole array is the only subarray
        if (k == n) return *max_element(nums.begin(), nums.end());

        // Case 3: check only nums[0] and nums[n-1]
        auto isUnique = [&](int idx) -> int {
            for (int i = 0; i < n; i++)
                if (i != idx && nums[i] == nums[idx]) return -1;
            return nums[idx];
        };

        return max(isUnique(0), isUnique(n-1));
    }
};