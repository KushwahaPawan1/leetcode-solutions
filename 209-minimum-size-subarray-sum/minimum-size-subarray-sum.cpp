class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int sum=0;
        int minLen=INT_MAX;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            while(sum>=target){
                int len=j-i+1;
                if(len<minLen) {
                    minLen=len;
                }
                //shrink kro left se 
                sum=sum-nums[i];
                i++;
            }
        }
        if(minLen==INT_MAX) return 0;
        return minLen;
    }
};