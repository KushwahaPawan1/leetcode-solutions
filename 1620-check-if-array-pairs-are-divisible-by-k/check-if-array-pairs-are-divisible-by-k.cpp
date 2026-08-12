class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        // Ye map har element ke remainder ki frequency store karega.
        //
        // Example:
        // arr = [1, 2, 3, 4, 5, 6], k = 5
        //
        // Remainders:
        // 1 -> 1
        // 2 -> 2
        // 3 -> 3
        // 4 -> 4
        // 5 -> 0
        // 6 -> 1
        //
        // To map kuch aisa hoga:
        // {0:1, 1:2, 2:1, 3:1, 4:1}
        unordered_map<int, int> mp;


        // Array ke har element ko traverse kar rahe hain
        for(int ele : arr){

            // Element ka remainder nikal rahe hain.
            //
            // Normally:
            // ele % k
            //
            // Lekin C++ mein negative number ka remainder
            // negative aa sakta hai.
            //
            // Example:
            // -1 % 5 = -1
            //
            // Hume remainder hamesha [0, k-1] ke range mein chahiye.
            //
            // Isliye:
            // ((ele % k) + k) % k
            //
            // Example:
            // ele = -1, k = 5
            // ((-1 % 5) + 5) % 5
            // = (-1 + 5) % 5
            // = 4
            //
            // Matlab -1 ka proper remainder 4 treat hoga.
            ele = ((ele % k) + k) % k;

            // Is remainder ki frequency increase kar do
            mp[ele]++;
        }


        // Ab remainder 0 wale elements ko handle karenge.
        //
        // Remainder 0 wale do numbers ko pair karne ke liye
        // unka sum bhi k ka multiple hona chahiye.
        //
        // Example:
        // 5 + 10 = 15
        // 15 % 5 = 0
        //
        // Isliye remainder 0 wale elements sirf
        // doosre remainder 0 elements ke saath pair honge.
        //
        // Is wajah se unki count EVEN honi chahiye.
        if(mp.find(0) != mp.end()){

            // Agar remainder 0 ki frequency odd hai,
            // to ek element bina pair ke bach jayega.
            if(mp[0] % 2 != 0) return false;

            // Remainder 0 ko handle kar liya,
            // isliye map se remove kar rahe hain.
            mp.erase(0);
        }


        // Ab baaki saare remainders ko check karenge.
        //
        // Agar kisi element ka remainder 'ele' hai,
        // to uske saath pair banane ke liye required remainder:
        //
        // rem = k - ele
        //
        // Example:
        // k = 5
        //
        // remainder 1 ko remainder 4 ke saath pair karna hoga:
        // 1 + 4 = 5
        //
        // remainder 2 ko remainder 3 ke saath pair karna hoga:
        // 2 + 3 = 5
        for(auto x : mp){

            // Current remainder
            int ele = x.first;

            // Is remainder ke saath pair banane ke liye
            // required remainder
            int rem = k - ele;


            // Check kar rahe hain ki required remainder map mein hai ya nahi.
            //
            // Example:
            // Agar ele = 2 aur k = 5,
            // to rem = 3 hona chahiye.
            //
            // Agar remainder 3 ka koi element hi nahi hai,
            // to remainder 2 wale elements pair nahi bana payenge.
            if(mp.find(rem) == mp.end()) return false;


            // Sirf remainder ka exist karna enough nahi hai.
            //
            // Dono remainders ki frequency bhi same honi chahiye.
            //
            // Example:
            // remainder 1 -> 3 elements
            // remainder 4 -> 3 elements
            //
            // Tab:
            // 1 + 4 = 5
            // aur saare pair ban sakte hain.
            //
            // Lekin agar:
            // remainder 1 -> 3
            // remainder 4 -> 2
            //
            // to ek remainder 1 wala element bina pair ke bach jayega.
            if(mp[ele] != mp[rem]) return false;
        }


        // Agar har remainder ka required complementary remainder
        // mil gaya aur dono ki frequencies equal hain,
        // to saare elements ko valid pairs mein arrange kiya ja sakta hai.
        return true;
    }
};