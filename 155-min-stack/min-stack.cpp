class MinStack {
public:
    stack<long long> st;
    long long min;   // Current minimum element ko store karega

    MinStack() { // Constructor
        min = LLONG_MAX;
    }

    void push(int val) {

        // Agar stack empty hai
        if (st.size() == 0) {

            st.push(val);
            min = val;   // Pehla element hi minimum hoga
        }

        // Agar naya element current minimum se bada ya equal hai
        else if (val >= min) {

            st.push(val);
        }

        // Agar naya element current minimum se chota hai
        else {

            // Fake (encoded) value push karo
            // Isse baad me purana minimum recover kar sakte hain
            st.push(2LL * val - min);

            // Current minimum update kar do
            min = val;
        }
    }

    void pop() {

        // Agar top fake value hai
        if (st.top() < min) {

            // Fake value ki help se purana minimum nikal lo
            long long oldMin = 2LL * min - st.top();

            // Purana minimum wapas set kar do
            min = oldMin;
        }

        // Top element remove kar do
        st.pop();
    }

    int top() {

        // Agar top fake value hai
        // To actual top current minimum hi hoga
        if (st.top() < min)
            return (int)min;

        // Warna normal value return karo
        else
            return (int)st.top();
    }

    int getMin() {

        // Current minimum return karo
        return (int)min;
    }
};

