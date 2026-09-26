class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<int> start;
        vector<int> end;

        for(auto interval : intervals) {
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0;
        int j = 0;

        int groups = 0;
        int res = 0;

        while(i < n) {

            if(start[i] <= end[j]) {
                // Naya interval start hua
                groups++;
                res = max(res, groups);
                i++;
            }
            else {
                // Ek interval end ho gaya
                groups--;
                j++;
            }
        }

        return res;
    }
};