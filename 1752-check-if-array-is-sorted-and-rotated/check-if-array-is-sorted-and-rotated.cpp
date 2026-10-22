class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int count=0;//  Agar poore circular array mein order maximum ek baar break hota hai ya ek bhi baar nahi , toh answer true hoga. Agar ek se zyada baar break hota hai, toh false.
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                count++;
            }
        }
        if(count==1|| count==0) return true;
        return false;
    }
};