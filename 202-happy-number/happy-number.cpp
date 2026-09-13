class Solution {
public:

    int nextNumber(int n) {
        int sum = 0;

        while(n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }

        return sum;
    }

    bool isHappy(int n) { //19

        int slow = n;  //19
        int fast = n;  //19

        while(true) {

            // slow → 1 step
            slow = nextNumber(slow); //82

            // fast → 2 steps
            fast = nextNumber(nextNumber(fast)); //68

            // agar 1 mil gaya → Happy
            if(slow == 1 || fast == 1)
                return true;

            // dono mil gaye → cycle hai
            if(slow == fast)
                return false;
        }
    }
};