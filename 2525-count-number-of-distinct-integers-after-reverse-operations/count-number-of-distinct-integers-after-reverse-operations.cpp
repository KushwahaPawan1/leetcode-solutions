class Solution {
public:
    // Function to reverse a number
    int reverse(int n) {
        int r = 0;

        while (n > 0) {
            // Make space for the next digit
            r *= 10;

            // Add the last digit of n to r
            r += (n % 10);

            // Remove the last digit from n
            n /= 10;
        }

        // Return the reversed number
        return r;
    }

    int countDistinctIntegers(vector<int>& nums) {

        // Store the original size because we'll keep adding new elements
        int n = nums.size();

        // Reverse every original number and append it to the vector
        for (int i = 0; i < n; i++) {

            // Get the reverse of the current number
            int rev = reverse(nums[i]);

            // Add the reversed number to the end of the vector
            nums.push_back(rev);
        }

        // Unordered set stores only unique elements
        unordered_set<int> s;

        // Insert every element of the updated vector into the set
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);   // Duplicate values are ignored automatically
        }

        // Number of unique elements
        return s.size();
    }
};