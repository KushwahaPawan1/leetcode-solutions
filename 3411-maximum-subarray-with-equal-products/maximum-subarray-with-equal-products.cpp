
class Solution {
public:

    int findGCD(int a, int b) {
        while(b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    int findLCM(int a, int b) {
        return (a / findGCD(a, b)) * b;
    }

    int maxLength(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {

            long long product = 1;
            int gcd = 0;
            int lcm = 1;

            for(int j = i; j < n; j++) {

                product *= nums[j];

                if(j == i) {
                    gcd = nums[j];
                    lcm = nums[j];
                }
                else {
                    gcd = findGCD(gcd, nums[j]);
                    lcm = findLCM(lcm, nums[j]);
                }

                if(product > 10000) break;

                if(product == 1LL * gcd * lcm) {
                    ans = max(ans, j-i+1);
                }
            }
        }

        return ans;
    }
};
