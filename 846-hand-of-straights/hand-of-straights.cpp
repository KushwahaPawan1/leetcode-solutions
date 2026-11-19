class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(),hand.end());
        int n= hand.size();
        if(n%groupSize!=0) return false; //equal pairs hi nhi ban sakte h 
        map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[hand[i]]++;
        }
      //1 2 2 3 3 4 6 7 8
        for(int startingNumber :hand){
            if(freq[startingNumber]==0){
                continue;
            } 
            
            for(int i=0;i<groupSize;i++){
                int reqNumber= startingNumber + i;//1 2 3 4
                //reqNumber available nhi h to return false
                if(freq[reqNumber]==0) return false;
                //jo numnber use kr lia h uski freq -- kro
                freq[reqNumber]--;
            }

        }
        return true;

    }
};