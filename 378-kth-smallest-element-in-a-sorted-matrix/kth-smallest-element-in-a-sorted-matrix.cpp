class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;

            int count = 0;

            // Mid se chhote ya equal elements count karenge
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] <= mid) {
                        count++;
                    }
                }
            }

            if (count < k) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return low;
    }
};