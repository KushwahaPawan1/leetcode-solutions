class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> ans(n, vector<int>(n));

        int minr = 0;
        int minc = 0;
        int maxr = n - 1;
        int maxc = n - 1;

        int num = 1;

        while(minr <= maxr && minc <= maxc){

            // Left to Right
            for(int j = minc; j <= maxc; j++){
                ans[minr][j] = num++;
            }
            minr++;

            // Top to Bottom
            for(int i = minr; i <= maxr; i++){
                ans[i][maxc] = num++;
            }
            maxc--;

            // Right to Left
            if(minr <= maxr){
                for(int j = maxc; j >= minc; j--){
                    ans[maxr][j] = num++;
                }
                maxr--;
            }

            // Bottom to Top
            if(minc <= maxc){
                for(int i = maxr; i >= minr; i--){
                    ans[i][minc] = num++;
                }
                minc++;
            }
        }

        return ans;
    }
};