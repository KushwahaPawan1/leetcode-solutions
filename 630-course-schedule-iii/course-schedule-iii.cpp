
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // S-1: Courses ko deadline (lastDay) ke ascending order mein sort karo
        sort(courses.begin(), courses.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        // S-2: Max Heap banao, jisme sabse zyada duration top par rahe
        priority_queue<int> pq;

        int totalDuration = 0;

        // S-3: Har course ko ek-ek karke check karo
        for (auto& course : courses) {
            int duration = course[0];
            int lastDay = course[1];

            // Current course ki duration total mein add karo
            totalDuration += duration;
            pq.push(duration);

            // Agar deadline cross ho gayi, toh longest course hata do
            if (totalDuration > lastDay) {
                totalDuration -= pq.top();
                pq.pop();
            }
        }

        // S-4: Heap mein jitne courses bache hain, wahi maximum count hai
        return pq.size();
    }
};
