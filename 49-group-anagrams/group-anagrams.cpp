class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        
        // Final answer store karne ke liye vector
        vector<vector<string>> ans;

        // Key = sorted string
        // Value = us sorted string ke corresponding saare anagrams
        unordered_map<string, vector<string>> mp;

        // Array ke har string par iterate karenge
        for(string str : arr){

            // Original string ki copy banayi
            string lexo = str;

            // String ko sort kar diya
            // Example: "eat" -> "aet"
            // "tea" -> "aet"
            // Isliye dono same key ke under aa jayenge
            sort(lexo.begin(), lexo.end());

            // Check kar rahe hain ki sorted string map mein already present hai ya nahi
            if(mp.find(lexo) == mp.end()){

                // Agar key pehli baar mili hai,
                // to ek naya vector banayenge
                vector<string> v;

                // Original string ko vector mein add kiya
                v.push_back(str);

                // Sorted string ko key aur vector ko value bana kar map mein store kiya
                mp[lexo] = v;
            }
            else{

                // Agar same sorted key already exist karti hai,
                // to current string ko uske vector mein add kar do
                mp[lexo].push_back(str);
            }
        }

        // Map ke har key-value pair par iterate karenge
        for(auto x : mp){

            // Current group of anagrams
            vector<string> v = x.second;

            // Group ko final answer mein add kar diya
            ans.push_back(v);
        }

        // Saare anagram groups return kar do
        return ans;
    }
};