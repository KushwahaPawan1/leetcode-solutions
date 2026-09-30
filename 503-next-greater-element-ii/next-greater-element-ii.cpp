class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);     // answer array, size n (har ans[i] hum khud set karenge)
        stack<int> st;          // stack me VALUES store hongi (index nahi)
                                // stack ke andar hamesha "right side ke possible greater candidates" rahenge

        // Circular array ko virtually do baar likha socho:
        // [1,2,3,4,3 | 1,2,3,4,3]  -> total 2n elements
        // Isliye i = 2n-1 se 0 tak right to left chal rahe hain
        for (int i = 2 * n - 1; i >= 0; i--) {

            // i 0 se 2n-1 tak ja sakta h, par asli array me index 0 se n-1 hi hain.
            // i % n se hume asli index mil jata h.
            // Example n=5: i=7 -> idx=2, i=5 -> idx=0, i=4 -> idx=4
            int idx = i % n;

            // Jab tak stack ka top current element se chhota ya barabar h,
            // wo current ke liye "strictly greater" nahi ban sakta.
            // Aur aage (left wale) elements ke liye bhi current hi behtar candidate h
            // (kyunki current right me zyada paas h aur bada/barabar h), to isko pop kar do.
            while (st.size() != 0 && st.top() <= nums[idx]) {
                st.pop();
            }

            // Answer sirf tab store karna h jab hum pehli copy me ho (i < n).
            // Doosri copy (i >= n) sirf stack ko "warm up" karne ke liye h,
            // taaki circular wale elements (jo array ke start me hain) stack me pehle se aa jayein.
            if (i < n) {
                // Stack khaali nahi h => top hi nearest next greater element h
                if (st.size() != 0) ans[idx] = st.top();

                // Stack khaali h => poore circular array me koi greater nahi mila, to -1
                else ans[idx] = -1;
            }

            // Current element ko push karo, ye left wale elements ke liye candidate banega.
            // Doosri copy me bhi push hota h (sirf answer store nahi hota).
            st.push(nums[idx]);
        }
        return ans;
    }
};