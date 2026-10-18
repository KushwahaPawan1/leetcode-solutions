class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int lo = 0;
        int high = rows - 1;

        // Pehle correct row find karenge
        while (lo <= high) {

            int mid = lo + (high - lo) / 2;

            // Target current row ke last element se bada hai
            if (target > matrix[mid][cols - 1]) {
                lo = mid + 1;
            }

            // Target current row ke first element se chhota hai
            else if (target < matrix[mid][0]) {
                high = mid - 1;
            }

            // Target current row ki range mein hai
            else {

                // Ab isi row mein binary search
                int left = 0;
                int right = cols - 1;

                while (left <= right) {

                    int midCol = left + (right - left) / 2;

                    if (matrix[mid][midCol] == target) {
                        return true;
                    }

                    else if (matrix[mid][midCol] < target) {
                        left = midCol + 1;
                    }

                    else {
                        right = midCol - 1;
                    }
                }

                return false;
            }
        }

        return false;
    }
};