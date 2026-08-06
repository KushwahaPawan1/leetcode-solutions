class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;

        // Har digit ki frequency store karo
        unordered_map<int, int> m;

        for (int ele : arr) {
            m[ele]++;
        }

        // Sirf 3-digit even numbers check karo
        for (int i = 100; i <= 999; i += 2) {

            int x = i;

            // Last digit
            int a = x % 10;
            x /= 10;

            // Middle digit
            int b = x % 10;
            x /= 10;

            // First digit
            int c = x;

            // Check karo 'a' digit available hai ya nahi
            if (m.find(a) != m.end()) { // agar 'a' present hai
                m[a]--;
                if (m[a] == 0) {
                    m.erase(a);
                }

                // Check karo 'b' digit available hai ya nahi
                if (m.find(b) != m.end()) { //agar 'b' present hai
                    m[b]--;

                    if (m[b] == 0) {
                        m.erase(b);
                    }

                    // Check karo 'c' digit available hai ya nahi
                    if (m.find(c) != m.end()) {
                        ans.push_back(i);
                    }

                    // b ko map me wapas restore karo
                    m[b]++;
                }

                // a ko map me wapas restore karo
                m[a]++;
            }
        }

        return ans;
    }
};