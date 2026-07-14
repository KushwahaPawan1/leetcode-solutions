class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {

        int n = arr.size();

        // ---------------- NSI (Next Smaller Index) ----------------
        // nsi[i] = right side me pehla chhota element ka index

        int nsi[n];
        stack<int> st;

        // Last element ke right me kuch nahi hota
        nsi[n - 1] = n;
        st.push(n - 1);

        // Right se Left traverse karenge
        for (int i = n - 2; i >= 0; i--) {

            // Jab tak current height chhoti ya equal hai,
            // stack se pop karte jao
            while (st.size() > 0 && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            // Agar stack empty ho gaya
            // Matlab right me koi smaller element nahi mila
            if (st.size() == 0)
                nsi[i] = n;
            else
                nsi[i] = st.top();

            // Current index stack me push karo
            st.push(i);
        }

        // ---------------- PSI (Previous Smaller Index) ----------------
        // psi[i] = left side me pehla chhota element ka index

        int psi[n];
        stack<int> gt;

        // Pehle element ke left me kuch nahi hota
        psi[0] = -1;
        gt.push(0);

        // Left se Right traverse karenge
        for (int i = 1; i < n; i++) {

            // Jab tak current height chhoti ya equal hai,
            // stack se pop karte jao
            while (gt.size() > 0 && arr[gt.top()] >= arr[i]) {
                gt.pop();
            }

            // Agar stack empty ho gaya
            // Matlab left me koi smaller element nahi mila
            if (gt.size() == 0)
                psi[i] = -1;
            else
                psi[i] = gt.top();

            // Current index stack me push karo
            gt.push(i);
        }

        // ---------------- Maximum Rectangle Area ----------------

        int maxArea = 0;

        for (int i = 0; i < n; i++) {

            // Current bar ki height
            int height = arr[i];

            // Width = NSI - PSI - 1
            int breadth = nsi[i] - psi[i] - 1;

            // Rectangle area
            int area = height * breadth;

            // Maximum area update karo
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};