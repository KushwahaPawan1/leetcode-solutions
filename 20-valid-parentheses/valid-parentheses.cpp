class Solution {
public:
    bool isValid(string s) {
        if (s.length()%2!=0) return false;
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else{//close wale brackets 
                if(st.size()==0) return false;
                // Matching check karo
                if (s[i] == ')' && st.top() != '(') return false;

                if (s[i] == '}' && st.top() != '{') return false;

                if (s[i] == ']' && st.top() != '[') return false;

                // Match ho gaya to opening bracket hata do
                st.pop();
            }
        }
        if(st.size()==0) return true;
        else return false;
    }
};