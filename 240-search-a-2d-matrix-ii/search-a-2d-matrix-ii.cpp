class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();      // Total rows
        int m = matrix[0].size();   // Total columns

        int row = n - 1;  // Last row se start karenge
        int col = 0;      // First column se start karenge (bottom-left corner)

        while(row >= 0 && col < m) {

            // Agar current element target ke equal hai
            // Toh target mil gaya, true return kar do
            if(matrix[row][col] == target)
                return true;

            // Agar current element target se bada hai
            else if(matrix[row][col] > target) {

                // Column ke elements sorted hain.
                // Current element se upar ke elements chhote honge,
                // aur current element se neeche ke elements bade honge.
                // Isliye current row ko eliminate karne ke liye upar move karo.
                row--;
            }

            // Agar current element target se chhota hai
            else {

                // Row ke elements sorted hain.
                // Current element ke left ke elements aur chhote honge.
                // Isliye current column ko eliminate karke right move karo.
                col++;
            }
        }

        // Agar target nahi mila aur hum matrix ki boundary ke bahar chale gaye
        return false;
    }
};