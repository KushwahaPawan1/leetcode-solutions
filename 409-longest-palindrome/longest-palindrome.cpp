class Solution {
public:
    int longestPalindrome(string s) {
        // Har character ki frequency store karne ke liye map
        unordered_map<char, int> f;

        // String ke har character ki count nikaal rahe hain
        for (int i = 0; i < s.size(); i++) {
            f[s[i]]++;
        }

        // Check karega ki koi odd-frequency character mila ya nahi
        bool odd = false;

        // Palindrome ki current maximum length
        int res = 0;

        // Even-frequency characters ko directly palindrome me use kar sakte hain
        for (auto i : f) {
            int val = i.second;

            if (val % 2 == 0) {
                res += val;
            } else {
                // Odd count wale character me ek character center ke liye bacha sakte hain
                odd = true;
            }
        }

        // Agar sab frequencies even hain, to poori string palindrome ban sakti hai
        if (odd == false)
            return res;

        // Odd-frequency characters se even part lete hain
        for (auto i : f) {
            int val = i.second;

            // Example: count = 5, to palindrome ke sides me 4 use honge
            if (val % 2 == 1)
                res += val - 1;
        }

        // Ek odd character palindrome ke center me add kar sakte hain
        return res + 1;
    }
};