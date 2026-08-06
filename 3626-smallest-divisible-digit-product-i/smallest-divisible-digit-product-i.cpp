class Solution {
public:

    int smallestNumber(int n, int t) {

        // n ko string me convert kiya
        string number = to_string(n);   // Example: n=15 -> "15"

        int prod = 1;

        // n ke saare digits ka product nikalo
        for (int i = 0; i < number.length(); i++) {
            prod = prod * (number[i] - '0');
        }

        // Agar n ke digits ka product t se divisible hai
        // to n hi smallest number hai
        if (prod % t == 0)
            return n;

        else {

            // n+1, n+2, n+3... check karte jao
            for (int i = 1; ; i++) {

                // Current number ko string me convert karo
                number = to_string(n + i);

                int prod = 1;

                // Current number ke digits ka product nikalo
                for (int j = 0; j < number.length(); j++) {
                    prod = prod * (number[j] - '0');
                }

                // Agar product t se divisible hai
                // to current number hi answer hai
                if (prod % t == 0)
                    return n + i;
            }
        }
    }
};