class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for (auto i:s){
            if (i==')'){
                if (!st.empty()&&st.top()=='(')st.pop();
                else return 0;
            }
            else if (i==']'){
                if (!st.empty()&&st.top()=='[')st.pop();
                else return 0;
            }
            else if (i=='}'){
                if (!st.empty()&&st.top()=='{')st.pop();
                else return 0;
            }
            else st.push(i);
        }
        return st.empty();
    }
};