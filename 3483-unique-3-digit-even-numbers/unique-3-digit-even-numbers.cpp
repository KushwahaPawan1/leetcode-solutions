class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int n = digits.size();
        set<int> st;

        for(int i = 0; i < n; i++) {

            // hundreds place: 0 nahi ho sakta
            if(digits[i] == 0) continue;

            for(int j = 0; j < n; j++) {

                // same digit ko dobara use nahi kar sakte
                if(j == i) continue;

                for(int k = 0; k < n; k++) {

                    // same digit ko dobara use nahi kar sakte
                    if(k == i || k == j) continue;

                    // ones place even hona chahiye
                    if(digits[k] % 2 != 0) continue;

                    int num = digits[i] * 100
                            + digits[j] * 10
                            + digits[k];

                    st.insert(num);
                }
            }
        }

        return st.size();
    }
};