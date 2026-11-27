class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int len=nums.size();
        sort(nums.begin(),nums.end());//2 3 4 6 8 
        int find=k;
        for(int i=0;i<len;i++){
            if(find==nums[i])  find+=k;
            else if(nums[i]>find) break;
        }
        return find;
    }

};