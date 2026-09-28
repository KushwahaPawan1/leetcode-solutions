class Solution {
public:
    int maxDepth(string s) {
        
        int n=s.size();
        int countOpen=0;
        int maxCountOpen=0;
        
        
        for(int i=0;i<n;i++){
            if(s[i]=='(') {
                countOpen++;
               maxCountOpen=max(countOpen,maxCountOpen);
            }
            else if(s[i]==')'){
                countOpen--;
            }
            else continue;
        }
        return maxCountOpen;
    }
};