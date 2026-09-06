class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int lo=0;
        int hi=n-1;
        int k=n-1;
        for(int i=0;i<n;i++){
            if(abs(nums[lo])>abs(nums[hi])){
                ans[k]=nums[lo]*nums[lo];
                k--;
                lo++;
            }
            else {//abs(nums[lo])<abs(nums[hi])
                ans[k]=nums[hi]*nums[hi];
                k--;
                hi--;
            }
        }
        return ans;
    }
};