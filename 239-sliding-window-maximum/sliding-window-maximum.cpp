class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // Agar window size 1 hai to har element hi us window ka maximum hoga
        if(k==1) return nums; 

        int n=nums.size();

        // Deque me elements nahi, unke indices store honge
        deque<int>dq;

        // Final answer store karne ke liye
        vector<int>ans;

        // Array ko left se right traverse karo
        for(int i=0;i<n;i++){

            // Current element se chhote elements kabhi future window ka maximum
            // nahi ban sakte, isliye unke indices remove kar do
            while(dq.size()>0 && nums[i]>nums[dq.back()])
                dq.pop_back();

            // Current element ka index deque me add karo
            dq.push_back(i);

            // Current window ka starting index
            int j=i-k+1;

            // Jo indices current window se bahar nikal gaye hain unhe hata do
            while(dq.size()>0 && dq.front()<j)
                dq.pop_front();

            // Jab first complete window ban jaye tab answer store karo
            // Deque ke front par hamesha current window ka maximum element hoga
            if(i>=k-1)
                ans.push_back(nums[dq.front()]);
        }

        // Sabhi windows ke maximum return kar do
        return ans;
    }
};