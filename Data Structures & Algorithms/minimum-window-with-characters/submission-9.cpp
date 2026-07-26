class Solution {
public:
    string minWindow(string s, string t)
    {
        int ans  = 100000 ;
        int low =0;
        int ss = s.size();
        int tt = t.size();
        if(ss<tt) return "";
        // if(ss == tt){
        //     if ( s == t) return s;
        //     else return "";
        // }
        vector<int> hT(256,0);
        vector<int> hS(256,0);
        int ind =0;
        int m =0;
        string str ="";
        for(int i=0;i<tt;i++){
            hT[t[i]]+=1;
        }
        for(int i=0;i<tt;i++){
            hS[s[i]]++;
            if(hT[s[i]] && hS[s[i]] <= hT[s[i]])
                m++;
        }
        int l=0;
        int r =tt;
        if (m == tt) {
            ans = tt;
            low = 0;
        }
        for(r =tt;r<ss;r++){
        // if(m == tt) return str;
            ind = s[r];
            hS[ind]+=1;
            // str+=s[r];
            if(hT[ind] && hS[ind] <= hT[ind])
                 m++;

            while(m==tt){

            if(r-l+1 < ans){
                ans = r-l+1;
                low = l;
            }

            ind = s[l];
            if(hT[ind] && hS[ind] <= hT[ind])
                m--;
            hS[ind]--;
            l++;
        }
        }
        if(ans == 100000)
            return "";

        return s.substr(low, ans);
    }
};
