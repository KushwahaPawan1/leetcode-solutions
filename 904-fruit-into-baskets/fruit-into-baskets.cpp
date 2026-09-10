class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k=2;
        int lo=0;
        int hi=0;
        int maxLen=INT_MIN;
        int n=fruits.size();
       
        unordered_map<int,int>mp;
        for(int hi=0;hi<n;hi++){
            mp[fruits[hi]]++;
            while(mp.size()>k){
                //shrink
                mp[fruits[lo]]--;
                if(mp[fruits[lo]]==0) {
                    //erase
                    mp.erase(fruits[lo]);
                }
                lo++;
            }
            if(mp.size()<=k){
                //answer update kro
                int currLen=hi-lo+1;
                if(currLen>maxLen) maxLen=currLen;
            }
        }
        if(maxLen==INT_MIN) return 0;
        else return maxLen;
    }
};