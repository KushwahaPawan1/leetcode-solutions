class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);      // answer array, size n
        stack<int> st;           // stack me temperature nahi, INDEX store honge

        ans[n-1] = 0;            // last din ke baad koi din nahi, to answer 0
        st.push(n-1);            // last index ko stack me daal diya

        // right se left traverse kar rahe hain (i = n-2 se 0 tak)
        for (int i = n - 2; i >= 0; i--) {

            // jab tak stack ka top (us index ka temp) <= current temp h,
            // wo warmer nahi h, to pop kar do
            while (st.size() != 0 && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // stack khaali => aage koi warmer din nahi
            if (st.size() == 0) ans[i] = 0;

            // warna top me nearest warmer din ka index h,
            // to distance = top index - current index
            else {
                ans[i] = st.top() - i;
            }

            // current index ko push karo, ye aage (left wale) elements ke kaam aayega
            st.push(i);
        }
        return ans;
    }
};