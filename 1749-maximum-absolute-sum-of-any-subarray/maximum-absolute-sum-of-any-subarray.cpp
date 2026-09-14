class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        //s-1 initialise 
        int currMax=nums[0];
        int currMin=nums[0];
        int ans = abs(nums[0]);
        int n=nums.size();
        //s-2 traverse 
        for(int i=1;i<n;i++){
            int c1=nums[i];
            int c2=currMax+nums[i];
            int c3=currMin+nums[i];
            currMax=max(c1,max(c2,c3));
            currMin=min(c1,min(c2,c3));
            ans=max(ans,max(abs(currMax),(abs(currMin))));
        }
        return ans;
    }
};