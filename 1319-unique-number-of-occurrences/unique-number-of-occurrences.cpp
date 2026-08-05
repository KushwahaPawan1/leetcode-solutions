class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        // Array ka size
        int n = arr.size();

        // unordered_map
        // key   -> array ka element
        // value -> us element ki frequency
        unordered_map<int, int> m;

        // Har element ki frequency count karo
        for (int i = 0; i < n; i++) {
            m[arr[i]]++;
        }

        // unordered_set frequencies ko store karega
        // Set sirf unique values store karta hai
        unordered_set<int> s;

        // Map ke har (element, frequency) pair ko traverse karo
        for (auto x : m) {

            // Current element ki frequency
            int freq = x.second;

            // Agar ye frequency pehle se set me hai,
            // matlab do elements ki frequency same hai
            if (s.find(freq) != s.end())
                return false;

            // Nahi hai to frequency ko set me store kar do
            else
                s.insert(freq);
        }

        // Saari frequencies unique hain
        return true;
    }
};