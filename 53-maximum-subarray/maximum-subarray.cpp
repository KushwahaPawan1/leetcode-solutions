class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //step 1 :initialaize kro
        int currMaxSum=nums[0];
        int maxSum=nums[0];
        int n=nums.size();
        //step:2 remaining part me traverse kro
        for(int i=1;i<n;i++){
            int c1=nums[i];
            int c2=nums[i]+currMaxSum;
            currMaxSum=max(c1,c2);
            maxSum=max(maxSum,currMaxSum);
        }
        return maxSum;

    }
};