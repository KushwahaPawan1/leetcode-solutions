class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {

        int n = arr.size();

        // NGI = Next Greater Index
        // ngi[i] = current element ke right me pehle greater element ka index
        int ngi[n];

        stack<int> st;

        // Last element ka koi next greater nahi hota
        ngi[n - 1] = n;
        st.push(n - 1);

        // Right se Left traverse karke NGI array bana rahe hain
        for (int i = n - 2; i >= 0; i--) {

            // Jab tak current element bada ya equal hai,
            // chhote elements ko stack se hata do
            while (st.size() > 0 && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            // Agar stack empty ho gaya,
            // matlab right me koi greater element nahi hai
            if (st.size() == 0)
                ngi[i] = n;
            else
                // Stack ka top hi next greater index hai
                ngi[i] = st.top();

            // Current index stack me push karo
            st.push(i);
        }

        vector<int> ans;

        // Har sliding window ke liye maximum nikalna hai
        for (int i = 0; i <= n - k; i++) {

            // Window ka start
            int j = i;

            // Initial maximum
            int mx = arr[i];

            // NGI ke through seedha next greater element par jump karenge
            while (j < i + k) {

                // Jis index par hain wahi current maximum hai
                mx = arr[j];

                // Next Greater Index par jump karo
                j = ngi[j];
            }

            // Is window ka maximum answer me store karo
            ans.push_back(mx);
        }

        return ans;
    }
};