class Solution {
public:
    // Function to reverse a given integer
    int reverse(int n) {
        int r = 0;

        while (n > 0) {
            // Shift existing digits one place to the left
            r *= 10;

            // Append the last digit of n to r
            r += (n % 10);

            // Remove the last digit from n
            n /= 10;
        }

        // Return the reversed number
        return r;
    }

    int countDistinctIntegers(vector<int>& nums) {

        // Store the original size of the vector
        int n = nums.size();

        // Unordered set to store only unique numbers
        unordered_set<int> s;

        // Traverse all original elements
        for (int i = 0; i < n; i++) {

            // Reverse the current number
            int rev = reverse(nums[i]);

            // Insert the original number into the set
            s.insert(nums[i]);

            // Insert the reversed number into the set
            // If it's already present, unordered_set ignores it
            s.insert(rev);
        }

        // Return the total number of distinct integers
        return s.size();
    }
};