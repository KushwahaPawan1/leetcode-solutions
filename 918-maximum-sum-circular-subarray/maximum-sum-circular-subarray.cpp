class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();

        // normal max
        int currMax = nums[0];
        int ansMax = nums[0];

        for(int i = 1; i < n; i++) {

            int c1 = nums[i];
            int c2 = nums[i] + currMax;

            currMax = max(c1, c2);

            ansMax = max(ansMax, currMax);
        }

        if(ansMax < 0)
            return ansMax;


        // circular array
        int totalSum = nums[0];

        for(int i = 1; i < n; i++) {
            totalSum += nums[i];
        }


        // minimum subarray sum
        int currMin = nums[0];
        int ansMin = nums[0];

        for(int i = 1; i < n; i++) {

            int v1 = nums[i];
            int v2 = nums[i] + currMin;

            currMin = min(v1, v2);

            ansMin = min(ansMin, currMin);
        }

        return max(ansMax, totalSum - ansMin);
    }
};