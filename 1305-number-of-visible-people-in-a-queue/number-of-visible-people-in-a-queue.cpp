class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {

        int n = arr.size();

        // Answer array, har person kitne log dekh sakta hai
        vector<int> ans(n, 0);

        // Stack me right side ke persons ki heights store hongi
        stack<int> st;

        // Sabse right wala kisi ko nahi dekh sakta
        st.push(arr[n - 1]);
        ans[n - 1] = 0;

        // Right se Left traverse karenge
        for (int i = n - 2; i >= 0; i--) {
            
            int count = 0;

            // Jab tak current person stack ke top se lamba hai,
            // current us person ko dekh sakta hai.
            // Isliye usse count karo aur stack se hata do.
            while (st.size() > 0 && arr[i] > st.top()) {
                st.pop();
                count++;
            }

            // Agar stack empty nahi hua,
            // to jo pehla taller/equal person bacha hai
            // woh bhi current ko dikhega.
            if (st.size() != 0)
                count++;

            // Current person ka answer store karo
            ans[i] = count;

            // Current person ko stack me push karo
            // taaki left wale log ise consider kar saken
            st.push(arr[i]);
        }

        return ans;
    }
};