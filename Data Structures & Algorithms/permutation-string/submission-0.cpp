class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hs1,hs2;
        int m = s1.size();
        int n = s2.size();
        int l=0;
        int r=0;
        int matches =0;
        int cnt =0;
        if(m>n) return false;   
        hs1.assign(26,0);
        hs2.assign(26,0);
        
        for(int i =0;i<m;i++){
            hs1[s1[i]-'a']+=1;
            hs2[s2[i]-'a']+=1;
        }

        for(int i = 0; i < 26; i++) {
    if(hs1[i] == hs2[i]) matches++;
}
        
        for(r =m;r<n;r++){
            if( matches == 26 ) return true;

            int ind = s2[r]-'a';
            hs2[ind]+=1;
            if( hs2[s2[r]-'a'] == hs1[s2[r]-'a']) matches +=1;
            else if(hs2[s2[r]-'a'] == hs1[s2[r]-'a']+1) matches-=1;

            ind = s2[l]-'a';
            hs2[ind]-=1;
            if( hs2[ind] == hs1[ind]) matches +=1;
            else if(hs2[ind] == hs1[ind]-1) matches-=1;
            l+=1;

        }
        return matches == 26;;
    }
};
