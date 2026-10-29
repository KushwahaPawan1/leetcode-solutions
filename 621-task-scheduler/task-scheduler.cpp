class Solution {
public:
    int leastInterval(vector<char>& tasks, int gap) {
        int n = tasks.size();

        // S-1: Har task ki frequency aur initial availability store karo
        unordered_map<char, int> freq;
        unordered_map<char, int> free;

        for (int i = 0; i < n; i++) {
            char task = tasks[i];

            freq[task]++;  // Task kitni baar aaya hai, uski frequency badhao

            // Shuru mein har task interval 1 par execute ho sakta hai
            free[task] = 1;
        }

        // S-2: Max Heap banao
        // Pair mein {frequency, task} store hoga
        // Jiski frequency sabse zyada hogi, woh heap ke top par rahega
        priority_queue<pair<int, char>> pq;

        for (auto entry : freq) {
            // entry.first  = task ka naam, jaise 'A'
            // entry.second = us task ki frequency, jaise 3
            pq.push({entry.second, entry.first});
        }

        int seat = 1;  // Current interval number

        // S-3: Jab tak saare tasks execute nahi ho jaate
        while (!pq.empty()) {

            // Is interval mein jo tasks execute nahi ho sakte,
            // unhe temporarily yahan store karenge
            vector<pair<int, char>> pulled;

            // S-4: Heap se available task dhoondho
            while (!pq.empty()) {
                // Sabse zyada frequency wala task nikalo
                pair<int, char> current = pq.top();
                pq.pop();

                int count = current.first;   // Task ki remaining frequency
                char task = current.second;  // Task ka naam

                // Check karo ki task current interval mein execute ho sakta hai ya nahi
                if (free[task] <= seat) {

                    // Task execute ho gaya, ab remaining frequency 1 kam karo
                    count--;

                    // Agar task ki frequency abhi bhi bachi hai,
                    // toh use dobara heap mein daal do
                    if (count > 0) {
                        pq.push({count, task});
                    }

                    // Gap maintain karne ke liye task ki next availability set karo
                    // Example: seat = 1, gap = 2
                    // Next availability = 1 + 2 + 1 = 4
                    free[task] = seat + gap + 1;

                    // Current interval mein ek task execute ho gaya,
                    // ab agle interval par move karenge
                    break;

                } else {
                    // Task abhi available nahi hai.
                    // Use temporary vector mein rakho taaki
                    // current interval mein doosra task check kar sakein
                    pulled.push_back(current);
                }
            }

            // S-5: Jo tasks temporarily nikale the,
            // unhe wapas max heap mein daal do
            for (int i = 0; i < pulled.size(); i++) {
                pq.push(pulled[i]);
            }

            // Ek interval complete hua.
            // Agar koi task execute nahi hua, toh yeh idle interval tha
            seat++;
        }

        // Loop ke end mein seat ek extra baar increment hota hai,
        // isliye total intervals = seat - 1
        return seat - 1;
    }
};