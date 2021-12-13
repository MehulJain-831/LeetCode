class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if(c == '{' || c == '[' || c == '('){
                st.push(c);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char t = st.top();
                st.pop();
                if(((t == '(') && (c != ')')) || ((t == '{') && (c != '}')) || ((t == '[') && (c != ']'))){
                    return false;
                }
            }
        }       
        return st.empty();
    }
};