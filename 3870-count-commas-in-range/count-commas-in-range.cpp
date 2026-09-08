class Solution {
public:
    int countCommas(int n) {
        if (n < 1000)
            return 0;

        string s = to_string(n);
        int comma = 0;

        for (int i = s.length() - 3; i > 0; i -= 3) {
            comma++;
        }

        return  (n-999)*comma;
    }
};