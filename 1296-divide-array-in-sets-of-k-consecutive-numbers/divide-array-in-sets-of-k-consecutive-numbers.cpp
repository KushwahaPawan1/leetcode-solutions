class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=n%k;
        if (ans!=0) return false;
        //else  set ban sakta h 
        map<int,int>freq;

        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }

        //har element ko starting point maan lo 
        for(int startingNumber : nums){
            //agar number already use ho chuka h to skip kr do 
            if (freq[startingNumber]==0) {
                continue;
            }

            //else pair banao
            for(int i=0;i<k;i++){
                int req_number =startingNumber+i;
                //req number available hai ya nhi 
                if(freq[req_number]==0) return false;

              // Number ko use kar liya, frequency decrease karo.
                freq[req_number]--;
            }
        }

        return true;
    }
};