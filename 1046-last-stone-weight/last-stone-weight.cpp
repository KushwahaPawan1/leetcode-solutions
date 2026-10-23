class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        for(int i=stones.size();stones.size() > 1;i--){
            sort(stones.begin(),stones.end());
            int n=stones.size();
            int x=stones[n-1];
            stones.pop_back();
            int y=stones[n-2];
            stones.pop_back();

            if(x!=y){
             stones.push_back(x-y);
            }
        }
        if(stones.size()==1) return stones[0];
        else return 0;
    }
};