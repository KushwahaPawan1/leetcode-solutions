class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int lo = 0;
        int hi = n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            // Target mil gaya
            if (nums[mid] == target) return mid;

            // nums[mid] > last element
            // Matlab mid P2 mein hai (bada wala left part)
            if (nums[mid] > nums[n - 1]) {

                // Target mid se bada hai
                // Dono P2 mein honge, target right mein milega
                if (target > nums[mid]) {
                    lo = mid + 1;
                }
                else {
                    // target < nums[mid]

                    // Target first element se bhi chhota hai
                    // Matlab target P1 mein hai, jo right side par hota hai
                    if (target < nums[0]) {
                        lo = mid + 1;
                    }
                    else {
                        // Target P2 mein hi hai, but mid se chhota hai
                        // Isliye left side mein search karo
                        hi = mid - 1;
                    }
                }
            }

            // nums[mid] <= last element
            // Matlab mid P1 mein hai (chhota wala right part)
            else {

                // Target mid se chhota hai
                // Dono P1 mein hain, target left mein hoga
                if (target < nums[mid]) {
                    hi = mid - 1;
                }
                else {
                    // target > nums[mid]

                    // Target last element se bada hai
                    // Matlab target P2 mein hai, jo left side par hota hai
                    if (target > nums[n - 1]) {
                        hi = mid - 1;
                    }
                    else {
                        // Target bhi P1 mein hai aur mid se bada hai
                        // Isliye right side mein search karo
                        lo = mid + 1;
                    }
                }
            }
        }

        // Target array mein nahi mila
        return -1;
    }
};