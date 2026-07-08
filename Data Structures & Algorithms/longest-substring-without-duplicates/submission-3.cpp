class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int h[256] = {0};
        int n = s.size();
        if(n <=1 ) return n;
        int ans = 1;
        int l=0, r=1;
        h[s[l]]+=1;
        while(r<n){
            char ele = s[r];
            if(h[ele] == 1 ){
                h[s[r]]+=1;
                while(s[l]!=s[r]){
                    h[s[l]]-=1;
                    l++;
                }
                h[s[l]]-=1;
                l+=1;
            }
            else{
                h[s[r]]+=1;
                ans = max(ans,r-l+1);
            }
            // h[s[r++]]+=1;
            r+=1;
        }
        return ans;         
    }
};
