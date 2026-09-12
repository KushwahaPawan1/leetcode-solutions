
class Solution {
public:

    // Check karega ki current window me
    // t ke saare required characters aa gaye hain ya nahi
    bool isValid(vector<int>& windowFreq, vector<int>& requiredFreq) {

        for(int i = 0; i < 256; i++) {

            // Agar window me kisi character ki frequency
            // required frequency se kam hai
            if(windowFreq[i] < requiredFreq[i])
                return false;
        }

        // Saare required characters sufficient quantity me hain
        return true;
    }

    string minWindow(string s, string t) {

        int n = s.size();
        int m = t.size();

        // requiredFreq:
        // t string me har character kitni baar chahiye
        vector<int> requiredFreq(256, 0);

        // windowFreq:
        // current window me har character kitni baar hai
        vector<int> windowFreq(256, 0);

        // Agar s chhoti hai t se,
        // toh answer possible hi nahi hai
        if(n < m)
            return "";

        // t ke characters ki frequency store karo
        for(int i = 0; i < m; i++) {
            requiredFreq[t[i]]++;
        }

        int low = 0;
        int high = 0;

        // Ab tak ki minimum valid window ki length
        int minLen = INT_MAX;

        // Minimum window kaha se start ho rahi hai
        int startIndex = -1;

        // high right side se window ko expand karega
        for(high = 0; high < n; high++) {

            // Current character ko window me add karo
            windowFreq[s[high]]++;

            // Jab tak current window valid hai,
            // tab tak left se shrink karte rahenge
            while(isValid(windowFreq, requiredFreq)) {

                // Current valid window ki length
                int currLen = high - low + 1;

                // Agar current window previous answer
                // se chhoti hai
                if(currLen < minLen) {

                    // Minimum length update karo
                    minLen = currLen;

                    // Answer ki starting position save karo
                    startIndex = low;
                }

                // Left wala character window se remove karo
                windowFreq[s[low]]--;

                // Left pointer ko aage badhao
                low++;
            }
        }

        // Agar koi valid window mili hi nahi
        if(minLen == INT_MAX)
            return "";

        // startIndex se minLen characters return karo
        return s.substr(startIndex, minLen);
    }
};
