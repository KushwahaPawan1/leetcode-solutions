class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //s-1 initialise kro
        int n=nums.size();
        int currMaxProd=nums[0];
        int currMinProd=nums[0];
        int maxProd=nums[0];
        //s-2 traverse array
        for(int i=1;i<n;i++){
            int c1=nums[i];
            int c2=nums[i]*currMaxProd;
            int c3=nums[i]*currMinProd;
            currMaxProd=max(c1,max(c2,c3));
            currMinProd=min(c1,min(c2,c3));
            maxProd=max(maxProd,max(currMaxProd,currMinProd));
        }
        return maxProd;

    }
};