class Solution {
public:
    unordered_map<int,bool> mp;
    bool f(int size,string s, vector<string>& wordDict){
        if(size == s.size()) return mp[size]= true;
        if(size > s.size()) return mp[size]= false;
        if(mp.find(size)!= mp.end()) return mp[size];
        bool b = false;
        int n = wordDict.size();
        for(int k =0;k<n;k++){
            if(wordDict[k] == s.substr(size,wordDict[k].size())) b = b or f(size+wordDict[k].size(),s,wordDict);
            if(b) return mp[size]= true;
        }
        return mp[size] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return f(0,s,wordDict);
    }
};
