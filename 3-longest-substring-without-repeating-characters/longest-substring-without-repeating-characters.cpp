class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int lo = 0;
        int hi = 0;
        int currLen = 0;
        int resultLen = 0;
        int n = s.size();

        unordered_map<char, int> mp;

        for(int hi = 0; hi < n; hi++){

            // current character ki frequency badhao
            mp[s[hi]]++;

            // agar duplicate hai toh lo ko aage badhao
            while(mp[s[hi]] >= 2){

                mp[s[lo]]--;

                // frequency 0 ho gayi toh hashmap se delete
                if(mp[s[lo]] == 0){
                    mp.erase(s[lo]);
                }

                lo++;
            }

            // ab window valid hai
            currLen = hi - lo + 1;

            resultLen = max(resultLen, currLen);
        }

        return resultLen;
    }
};