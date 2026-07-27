class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string& c:tokens){
            if(isdigit(c[c.size()-1])){
                st.push(stoi(c));
            }
            else{
                int a =st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (c == "+") st.push(b + a);
                else if (c == "-") st.push(b - a);
                else if (c == "*") st.push(b * a);
                else if (c == "/") st.push(b / a);
            }
        }
        return st.top();
    }
};
