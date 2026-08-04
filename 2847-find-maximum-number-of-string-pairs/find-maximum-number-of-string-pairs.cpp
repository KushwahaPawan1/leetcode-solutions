class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& arr) {

        // Total number of strings
        int n = arr.size();

        // Final answer (number of valid pairs)
        int count = 0;

        // Unordered set me saari strings store karenge
        // Taaki O(1) average time me search kar sake
        unordered_set<string> s;

        // Saari strings set me insert kar do
        for (int i = 0; i < n; i++) {
            s.insert(arr[i]);
        }

        // Har string ke liye check karenge ki uska reverse present hai ya nahi
        for (int i = 0; i < n; i++) {

            // Current string ki copy banao
            string rev = arr[i];

            // Us copy ko reverse kar do
            reverse(rev.begin(), rev.end());

            // Agar string already palindrome hai (jaise "aa")
            // to usse pair nahi bana sakte, isliye skip kar do
            if (arr[i] == rev)
                continue;

            // Agar reverse string set me present hai
            if (s.find(rev) != s.end()) {

                // Ek valid pair mil gaya
                count++;

                // Current string ko set se remove kar do
                // Taaki same pair dobara count na ho
                s.erase(arr[i]);
            }
        }

        // Total valid pairs return karo
        return count;
    }
};