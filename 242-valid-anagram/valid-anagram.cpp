class Solution {
public:
    bool isAnagram(string s, string t) {

        // Agar length different hai to anagram possible hi nahi
        if (s.length() != t.length()) return false;

        // map1 me string s ke har character ki frequency store hogi
        unordered_map<char, int> map1;

        // String s ki frequency count karo
        for (int i = 0; i < s.length(); i++) {
            map1[s[i]]++;
        }

        // String t ke har character ko process karo
        for (int i = 0; i < t.length(); i++) {

            char ch = t[i];

            // Agar character map me present hai
            if (map1.find(ch) != map1.end()) {

                // Frequency 1 se kam kar do
                map1[ch]--;

                // Agar frequency 0 ho gayi to map se remove kar do
                if (map1[ch] == 0)
                    map1.erase(ch);
            }

            // Character mila hi nahi, matlab anagram nahi hai
            else {
                return false;
            }
        }

        // Agar map empty hai to saari frequencies match ho gayi
        if (map1.size() > 0)
            return false;

        return true;
    }
};