class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        // vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        vector<int> curr(n+1,0);
        vector<int> prev(n+1,0);
        for(int r = m-1;r>=0;r--){
            for(int c = n-1;c>=0;c--){
                if(s1[r] == s2[c]) curr[c] = 1+prev[c+1];
                else curr[c] = max(curr[c+1],prev[c]);
            }
            prev=curr;
        }
        return prev[0];
    }
};
