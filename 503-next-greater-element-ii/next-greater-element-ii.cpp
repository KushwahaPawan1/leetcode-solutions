class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);     // answer array, har ans[i] hum khud set karenge
        stack<int> st;          // stack me VALUES store hongi

        // PHASE 1: Stack ko "circular wale elements" se pehle hi bhar do.
        // Last element (n-1) ke baad circular me agla element nums[0], phir nums[1], ... aata h.
        // Isliye nums[n-2] se nums[0] tak push karte hain, taaki
        // stack ka top = nums[0], uske neeche nums[1], nums[2], ... (bottom me nums[n-2]).
       
        // Note: yahan pop nahi kar rahe, to stack monotonic nahi h, par order sahi h
        for (int i = n - 2; i >= 0; i--) {
            st.push(nums[i]);   // example [1,2,3,4,3]: stack (bottom->top) = 4,3,2,1
        }

        // PHASE 2: Asli traversal, right se left (i = n-1 se 0)
        for (int i = n - 1; i >= 0; i--) {

            // Jab tak top <= current, wo "strictly greater" nahi h, pop kar do.
            // Pop karna safe h, kyunki current (jo aage push hoga) us popped element se
            // bada/barabar h aur circular order me usse pehle aata h,
            // to left wale elements ke liye current hi behtar candidate rahega.
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            // Stack khaali => poore circular array me koi greater nahi, to -1
            if (st.empty()) ans[i] = -1;

            // Warna top hi nearest next greater h (circular order me sabse paas wala)
            else ans[i] = st.top();

            // Current ko push karo, ye left wale elements ke liye candidate banega
            st.push(nums[i]);
        }
        return ans;
    }
};