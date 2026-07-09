class Solution {
public:
    bool isValid(string s) {
        // int o1 =0,o2=0,o3=0;
        stack<int> st;

        int n = s.size();
        for(int i =0 ; i<n; i++){
            char c = s[i];
            if( c == '(') st.push(c);
            else if( c == '{') st.push(c);
            else if ( c == '[') st.push(c);
            else if(!st.empty()){
                if(c == ')' ){
                    if (st.top() == '(') st.pop();
                    else return false;
                }
                if(c == '}' ){
                    if (st.top() == '{') st.pop();
                    else return false;
                }
                if(c == ']' ){
                    if (st.top() == '[') st.pop();
                    else return false;
                }
            }
            else{
                return false;
            }           
        }
        if(st.empty() ) return true;
        else return false;
    }
};
