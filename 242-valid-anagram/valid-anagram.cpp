class Solution {
public:
    bool isAnagram(string s, string t) {

        // Agar dono strings ki length different hai,
        // to wo kabhi anagram nahi ho sakti
        if (s.length() != t.length())
            return false;

        // map1 me string s ke har character ki frequency store hogi
        // key   = character
        // value = us character ki frequency
        unordered_map<char, int> map1;

        // map2 me string t ke har character ki frequency store hogi
        unordered_map<char, int> map2;


        // String s ke har character ki frequency count karo
        for (int i = 0; i < s.length(); i++) {

            // Agar character pehli baar aaya to value initially 0 hogi
            // ++ karne ke baad 1 ho jayegi
            // Agar already present hai to frequency 1 se increase hogi
            map1[s[i]]++;
        }


        // String t ke har character ki frequency count karo
        for (int i = 0; i < t.length(); i++) {

            // Har character ki frequency map2 me store karo
            map2[t[i]]++;
        }


        // map1 ke har character aur uski frequency ko check karo
        for (auto x : map1) {

            // x.first me character/key milega
            char ch1 = x.first;

            // x.second me us character ki frequency milegi
            int freq1 = x.second;


            // Check karo ki same character map2 me present hai ya nahi
            if (map2.find(ch1) != map2.end()) {

                // map2 me same character ki frequency nikalo
                int freq2 = map2[ch1];

                // Agar dono strings me character ki frequency different hai
                // to strings anagram nahi hain
                if (freq1 != freq2)
                    return false;
            }

            // Agar character map2 me mila hi nahi,
            // to strings anagram nahi hain
            else {
                return false;
            }
        }

        // Saare characters ki frequency same mili
        // isliye dono strings anagram hain
        return true;
    }
};