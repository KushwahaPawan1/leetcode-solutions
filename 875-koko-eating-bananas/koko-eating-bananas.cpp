class Solution {
public:
    long long fun(vector<int>& piles, int n, int currSpeed) {
        long long hourUsed = 0;

        for (int i = 0; i < n; i++) {

            // Current pile ko currSpeed ki speed se khane mein lagne wale hours
            hourUsed += piles[i] / currSpeed;

            // Agar bananas poori tarah divide nahi hue,
            // toh bache hue bananas khane ke liye 1 extra hour lagega
            if (piles[i] % currSpeed != 0) {
                hourUsed = hourUsed + 1;
            }
        }

        // Total piles ko khane mein kitne hours lagenge, woh return karo
        return hourUsed;
    }

    int minEatingSpeed(vector<int>& piles, int guard) {
        int n = piles.size();

        int lo = 1;  // Minimum possible eating speed
        int hi = 0;

        // Maximum pile size find kar rahe hain
        // Kyunki maximum speed par ek pile ko 1 hour mein khaya ja sakta hai
        for (int i = 0; i < n; i++) {
            hi = max(piles[i], hi);
        }

        int minSpeed = 0;  // Minimum valid speed store karega

        // Jab tak search space valid hai, Binary Search chalao
        while (lo <= hi) {

            // Mid ko current eating speed maan kar check karenge
            int mid = lo + (hi - lo) / 2;

            // Current speed par total kitne hours lagenge
            long long TotalHourTaking = fun(piles, n, mid);

            if (TotalHourTaking > guard) {

                // Hours allowed limit se zyada hain
                // Isliye speed badhani padegi
                // Right half mein search karo
                lo = mid + 1;

            } else {

                // Current speed mein saare bananas allowed hours mein kha sakte hain
                // Ye ek valid answer hai, ise store kar lo
                minSpeed = mid;

                // Isse bhi kam speed possible hai ya nahi, check karo
                // Isliye left half mein search karo
                hi = mid - 1;
            }
        }

        // Minimum valid eating speed return karo
        return minSpeed;
    }
};