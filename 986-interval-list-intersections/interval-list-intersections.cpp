class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>>res;
        int i=0;
        int j=0;

        while(i<a.size() && j<b.size()){
            int start1=a[i][0];
            int end1=a[i][1];
 
            int start2=b[j][0];
            int end2=b[j][1];

            //case1: agar interval 1 ka start chhota h interval 2 se
            if(start1<=start2){
                //check kro overlapping ho rhi ya nhi 
                if(end1>=start2){
                    //overlap ka start = badi wali value
                    int s=max(start1,start2);
                    //overlap ka end = chhoti wali value
                    int e=min(end1,end2);

                    res.push_back({s,e});
                }
            }
            //case 2: Interval 2 ka start chhota h interval 1 se
            else{//if(start2<=start1){
                //check kro ki overlap ho raha h ya nhi 
                if(end2>=start1){
                    //overlap ka start = bada start
                    int s=max(start1,start2);
                    //overlap ka end=chhota end
                    int e=min(end1,end2);

                    res.push_back({s,e});
                }
            }
            //jiska end chhota hai(vo khtm ho jaega pehle ) ,us interval ko aage badhao 
            if(end1<=end2){
                i++;
            }    
            else {
                j++;
            }
        }
        return res;

        
    }
};