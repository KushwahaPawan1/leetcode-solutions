class Solution {
public:

    struct comp {//min,max
        bool operator()(pair<int,string> a, pair<int,string> b) {

            // Agar dono words ki frequency same hai
            if(a.first == b.first) {
                // Alphabetically bada word top par rahega
                return a.second < b.second;
            }

            // Frequency kam wala word top par rahega
            return a.first > b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();

        unordered_map<string,int>mp;//{word,freq}

        // Har word ki frequency count karo
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }

        // Custom comparator ke saath Min Heap declare karo
        priority_queue<pair<int,string>,
                       vector<pair<int,string>>,comp>pq;

        // Map ke har word ko heap me insert karo
        for(auto i:mp){
            string ele=i.first;
            int freq=i.second;

            // Pair me pehle frequency, phir word store kiya
            pair<int,string>p={freq,ele};

            pq.push(p);

            // Agar heap ka size k se bada ho jaye
            if(pq.size()>k){
                // Sabse kam priority wala word remove karo
                pq.pop();
            }
        }

        // Ab heap me top k frequent words hain
        vector<string>ans;

        // Heap se words nikaal kar answer me store karo
        while(pq.size()>0){
            // Pair ka second element word hai
            string curr = pq.top().second;
            ans.push_back(curr);
            pq.pop();
        }

        // Frequency descending aur alphabetical order sahi karne ke liye
        reverse(ans.begin(),ans.end());

        // Final answer return karo
        return ans;
    }
};