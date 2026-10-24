class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        //s-1 capital aur profit ko ek pair bana k vector me store kia
        vector<pair<int,int>>projects;//{capital,profits}
        for(int i=0;i<n;i++){
            projects.push_back({capital[i],profits[i]});
        }
        //s-2 Capital ke increasing order mein sort karo
        sort(projects.begin(),projects.end());
        //s-3 max heap banao jo profit store karega 
        priority_queue<int>pq;
        int idx=0;
        //s-4 max k projects select krne h 
        while(k--){
            while(idx<n && projects[idx].first<=w){
                //profits store karna h 
                pq.push(projects[idx].second);
                idx++;
            }
            // Koi project affordable nahi hai to w hi return krke khatam program
            if(pq.empty()){
                return w;
            }
            //ab heap khali nhi h means profits store h heap me
             // Sabse zyada profit wala project select karo
             w+=pq.top();
             pq.pop(); 
        }
        return w;

    }
};