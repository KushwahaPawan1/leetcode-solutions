class Solution {
public:

    typedef pair<int,int> pi;//{freq,ele}

    vector<int> topKFrequent(vector<int>& arr, int k) {

        unordered_map<int,int> mp; //{ele,freq}

        // Har element ki frequency count karo
        for(int ele : arr){
            mp[ele]++;
        }

        /*
            Min Heap banaya hai.

            Heap ke andar pair:
            <frequency, element>

            Sabse kam frequency wala element
            heap ke top par rahega.
        */

        priority_queue<pi,vector<pi>,greater<pi>> pq;

        /*
            Map ke har element ko heap me daalenge.

            Agar heap ka size k se bada ho gaya,
            toh sabse kam frequency wala element
            remove kar denge.

            Isse heap me sirf TOP k frequent
            elements bachenge.
        */

        for(auto x : mp){

            // x.first  = element
            // x.second = frequency

            int ele = x.first;
            int freq = x.second;


            // Pair banaya:
            // {frequency, element}
            pair<int,int> p = {freq, ele};


            // Pair ko Min Heap me insert karo
            pq.push(p);


            // Sirf k elements heap me maintain karo
            if(pq.size() > k)
                pq.pop();
        }


        // Answer store karne ke liye vector
        vector<int> ans;


        /*
            Heap me ab sirf k most frequent elements hain.

            Heap ke top se element nikalte jao
            aur answer vector me store karo.
        */

        while(pq.size() > 0){

            // pair = {frequency, element}
            // second = element
            int ele = pq.top().second;

            // Element ko answer me add karo
            ans.push_back(ele);

            // Heap se top element remove karo
            pq.pop();
        }


        // Top K frequent elements return karo
        return ans;
    }
};