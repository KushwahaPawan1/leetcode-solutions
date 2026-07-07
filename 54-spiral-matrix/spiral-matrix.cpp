class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;

        int m = matrix.size();
        int n = matrix[0].size();

        int minr = 0;
        int minc = 0;
        int maxr = m - 1;
        int maxc = n - 1;

        while(minr <= maxr && minc <= maxc){

            // Left to Right
            for(int j = minc; j <= maxc; j++){
                ans.push_back(matrix[minr][j]);
            }
            minr++;

            // Top to Bottom
            for(int i = minr; i <= maxr; i++){
                ans.push_back(matrix[i][maxc]);
            }
            maxc--;

            // Right to Left
            if(minr <= maxr){
                for(int j = maxc; j >= minc; j--){
                    ans.push_back(matrix[maxr][j]);
                }
                maxr--;
            }

            // Bottom to Top
            if(minc <= maxc){
                for(int i = maxr; i >= minr; i--){
                    ans.push_back(matrix[i][minc]);
                }
                minc++;
            }
        }

        return ans;
    }
};