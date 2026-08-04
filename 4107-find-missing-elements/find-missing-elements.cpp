class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;//khali ans naam ka vector ban gaya
        sort(nums.begin(),nums.end());//1 2 4 5 sort kar dia
        int n=nums.size();
        int min=nums[0];
        int max=nums[n-1];
        for(int i=0;i<n-1;i++){
            int target=nums[i]+1;
            while(target< nums[i+1]){
                ans.push_back(target);
                target++;
            }
        }
        return ans;
    }
};