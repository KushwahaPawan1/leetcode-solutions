//method 2
class MyQueue {
public:
stack<int>st;
stack<int>helper;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st.size()==0){
             st.push(x);
            return;
        }
        else{
            while(st.size()>0){
                helper.push(st.top());
                st.pop();
            }
            st.push(x);
            while(helper.size()>0){
             st.push(helper.top());
             helper.pop();
            }

        }
       
        
    }
    
    int pop() {//remove at bottom...use heloer stack
       int x=st.top();
       st.pop();
       return x;

    }
    
    int peek() {//return front
      return st.top(); 
    }
    
    bool empty() {
        if(st.size()==0) return true;
        else return false;
    }
};

