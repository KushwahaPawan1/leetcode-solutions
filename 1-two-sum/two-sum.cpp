class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Final answer store karega (2 indices)
        vector<int> ans;

        // Array ka size
        int n = nums.size();

        // unordered_map
        // key   -> number
        // value -> us number ka index
        unordered_map<int, int> m;

        // Array ko ek hi baar traverse karenge
        for (int i = 0; i < n; i++) {

            // Current number ke liye required number nikalo
            // jisse dono ka sum = target ho jaye
            int rem = target - nums[i];

            // Check karo ki required number pehle se map me present hai ya nahi
            if (m.find(rem) != m.end()) {

                // Agar present hai to uska index answer me add karo
                ans.push_back(m[rem]);

                // Current element ka index bhi add kar do
                ans.push_back(i);

                // Answer mil gaya, return kar do
                return ans;
            }

            // Agar required number nahi mila,
            // to current number aur uska index map me store kar do
            else {
                m[nums[i]] = i;
            }
        }

        // Agar pair na mile (LeetCode me normally kabhi execute nahi hota)
        return ans;
    }
};