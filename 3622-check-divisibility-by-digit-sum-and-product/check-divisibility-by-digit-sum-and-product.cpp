class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int sum = 0;
        long long prod = 1;

        while (n > 0) {
            int lastDigit = n % 10;

            sum += lastDigit;
            prod *= lastDigit;

            n /= 10;
        }

        return original % (sum + prod) == 0;
    }
};