class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> dp(m+1,0);
        dp[m] = 1;
        int temp = 1;
        for(int i = n-1;i>=0;i--){
            int prev =1;
            for(int j=m-1;j>=0;j--){
                temp = dp[j];
                if(s[i] == t[j])
                    dp[j] = prev+dp[j];
                else 
                    dp[j] = dp[j];
                prev = temp;
            }
        }
        return dp[0];
    }
};
