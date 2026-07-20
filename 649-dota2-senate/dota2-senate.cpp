class Solution {
public:
    string predictPartyVictory(string s) {

        // Sabhi senators ki turn maintain karne ke liye
        queue<int>q;

        // Radiant aur Dire ke indices alag-alag store karenge
        queue<int>r;
        queue<int>d;

        // Sabhi indices queues me daal do
        for(int i=0;i<s.length();i++){
            q.push(i);

            // Agar Radiant hai to r queue me
            if(s[i]=='R') r.push(i);

            // Warna Dire queue me
            else d.push(i);
        }

        // Jab tak ek se zyada senators process hone baaki hain
        while(q.size()>1){

            // Agar ye senator pehle hi ban ho chuka hai to ise skip kar do
            if(s[q.front()]=='X')
                q.pop();

            // Agar current senator Radiant hai
            else if(s[q.front()]=='R'){

                // Agar koi Dire bacha hi nahi to Radiant jeet gaya
                if(d.size()==0)
                    return "Radiant";

                else{

                    // Sabse pehle wale Dire senator ko ban kar do
                    s[d.front()]='X';
                    d.pop();

                    // Current Radiant ka turn complete ho gaya,
                    // ise next round ke liye queue ke end me bhej do
                    q.push(q.front());
                    q.pop();

                    // Radiant ki queue bhi rotate kar do
                    r.push(r.front());
                    r.pop();
                }
            }

            // Agar current senator Dire hai
            else{

                // Agar koi Radiant bacha hi nahi to Dire jeet gaya
                if(r.size()==0)
                    return "Dire";

                else{

                    // Sabse pehle wale Radiant senator ko ban kar do
                    s[r.front()]='X';
                    r.pop();

                    // Current Dire ka turn complete,
                    // ise next round ke liye end me bhej do
                    q.push(q.front());
                    q.pop();

                    // Dire ki queue bhi rotate kar do
                    d.push(d.front());
                    d.pop();
                }
            }
        }

        // Last bacha hua senator jis party ka hoga wahi winner hoga
        if(s[q.front()]=='R')
            return "Radiant";
        else
            return "Dire";
    }
};