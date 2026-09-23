class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> res;
        int n = intervals.size();

        // S-1: Intervals ko starting point ke according sort karo
        sort(intervals.begin(), intervals.end());

        // S-2: Pehle interval ko current interval maan lo
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        // S-3: Baaki intervals ko ek-ek karke check karo
        for(int i = 1; i < n; i++) {

            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            // Agar current interval aur next interval overlap kar rahe hain
            if(end1 >= start2) {

                // Dono ko merge karo
                // End wahi hoga jo dono me se bada hai
                end1 = max(end1, end2);

                // Merge ho gaya, ab next interval check karo
                continue;
            }

            // Agar overlap nahi hai,
            // to current interval ko result me daal do
            res.push_back({start1, end1});

            // Ab next interval ko current interval bana do
            start1 = start2;
            end1 = end2;
        }

        // Last bacha hua interval bhi result me daal do
        res.push_back({start1, end1});

        return res;
    }
};