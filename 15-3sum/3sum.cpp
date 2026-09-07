class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            // Duplicate first element skip
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int lo = i + 1;
            int hi = n - 1;

            while (lo < hi) {

                int sum = nums[i] + nums[lo] + nums[hi];

                if (sum == 0) {

                    ans.push_back({nums[i], nums[lo], nums[hi]});

                    lo++;
                    hi--;

                    // Duplicate left values skip
                    while (lo < hi && nums[lo] == nums[lo - 1])
                        lo++;

                    // Duplicate right values skip
                    while (lo < hi && nums[hi] == nums[hi + 1])
                        hi--;
                }

                else if (sum < 0) {
                    // Sum chhota hai → bada number chahiye
                    lo++;
                }

                else {
                    // Sum bada hai → chhota number chahiye
                    hi--;
                }
            }
        }

        return ans;
    }
};