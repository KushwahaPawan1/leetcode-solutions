
class Solution {
public:

    // Ye function frequency vector me se
    // sabse badi frequency return karega
    int find(vector<int>& v) {

        int maxC = -1;

        // 0 se 255 tak saari frequencies check karenge
        for(int i = 0; i < 256; i++) {

            // Sabse badi frequency store karte rahenge
            maxC = max(maxC, v[i]);
        }

        return maxC;
    }

    int characterReplacement(string s, int k) {

        int lo = 0;

        int n = s.size();

        // Ab tak ki maximum valid window ki length
        int maxLen = INT_MIN;

        // Har character ki frequency store karega
        // Example: 'A' = ASCII 65
        // toh v[65] me A ki frequency store hogi
        vector<int> v(256, 0);

        // hi window ko right side se expand karega
        for(int hi = 0; hi < n; hi++) {

            // Current character ki frequency increase karo
            v[s[hi]]++;

            // Current window me sabse zyada
            // baar aane wale character ki frequency
            int maxCount = find(v);

            // Current window ki length
            int currLen = hi - lo + 1;

            // Window ko ek hi character ka banane ke liye
            // kitne characters replace karne padenge
            int diff = currLen - maxCount;

            // Agar required replacements k se zyada hain
            // toh current window invalid hai
            while(diff > k) {

                // Left wale character ki frequency kam karo
                v[s[lo]]--;

                // Left pointer ko aage badhao
                lo++;

                // Window change ho gayi,
                // isliye maximum frequency dobara calculate karo
                maxCount = find(v);

                // Updated window ki length
                currLen = hi - lo + 1;

                // Updated replacements required
                diff = currLen - maxCount;
            }

            // Ab window valid hai
            currLen = hi - lo + 1;

            // Maximum valid window update karo
            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};
