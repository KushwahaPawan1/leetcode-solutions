class MyQueue {
public:
stack<int>st;
stack<int>helper;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
        
    }
    
    int pop() {//remove at bottom...use heloer stack
        while(st.size()>0){
            helper.push(st.top());
            st.pop();
        }
        int x=helper.top();
        helper.pop();

         while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
        return x;

    }
    
    int peek() {//return front
         while(st.size()>0){
            helper.push(st.top());
            st.pop();
        }
        int x=helper.top();
         while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
        return x;

    }
    
    bool empty() {
        if(st.size()==0) return true;
        else return false;
    }
};

