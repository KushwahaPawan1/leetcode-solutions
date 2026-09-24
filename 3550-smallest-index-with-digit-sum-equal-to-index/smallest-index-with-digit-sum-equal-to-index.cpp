class Solution {
public:
    int digitSum(int number) {
        int sum = 0;

        while(number > 0) {
            sum += number % 10;
            number /= 10;
        }

        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int currentDigitSum = digitSum(nums[i]);

            if(currentDigitSum == i)
                return i;
        }

        return -1;
    }
};