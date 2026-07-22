class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans =0;
        for(int i =0;i<n;i++){
            int l=i;
            int r =i;
            while(l>=0 and r<s.size() and s[l]==s[r]){
                ans+=1;
                l-=1;
                r+=1;
            }

            l=i;
            r =i+1;
            while(l>=0 and r<s.size() and s[l]==s[r]){
                ans+=1;
                l-=1;
                r+=1;
            }

        }
        return ans;
    }
};
