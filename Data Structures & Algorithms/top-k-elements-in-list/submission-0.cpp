class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // int has[3000] = {0};
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]+=1;
        }
        int n = nums.size()+1;
        vector<vector<int>> freq(n);
        for(auto it:mp){
            freq[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i =n-1;i>0;i--){
            if(!freq[i].empty()){

            
            for (int x : freq[i]) {
                ans.push_back(x);
                k--;
                if (k == 0) break;
            }}
            if(k==0) break;
        }
        return ans;
    }
};
