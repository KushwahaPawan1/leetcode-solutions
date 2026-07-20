class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        int n = deck.size();

        // Cards ko increasing order me sort kar do
        sort(deck.begin(), deck.end());

        // Queue me answer array ke saare indices store karenge
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(i);
        }

        // Final arrangement store karne ke liye
        vector<int> ans(n);

        // Ek-ek karke sorted cards ko unki correct position par rakho
        for (int i = 0; i < n; i++) {

            // Queue ke front par jo index hai wahi current card ki position hogi
            int idx = q.front();
            q.pop();

            // Current smallest card ko us position par rakh do
            ans[idx] = deck[i];

            // Agar queue me aur indices bache hain to
            // front wale index ko back me bhej do
            // (Reveal process ko reverse simulate kar rahe hain)
            if (q.size()>0) {
                q.push(q.front());
                q.pop();
            }
        }

        // Final deck arrangement return kar do
        return ans;
    }
};