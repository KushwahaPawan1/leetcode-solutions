class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (st.size() != 0 && st.top() <= nums[i]) {
                st.pop();
            }

            if (st.size() != 0) ans[i] = st.top();   // right me hi mil gaya
            else {
                ans[i] = -1;                         // pehle -1 maan lo (i=0 ke liye bhi set ho jayega)

                // circular: left me pehla greater dhundo
                for (int j = 0; j < i; j++) {
                    if (nums[j] > nums[i]) {
                        ans[i] = nums[j];            // mila to overwrite
                        break;
                    }
                }
            }

            st.push(nums[i]);
        }
        return ans;
    }
};