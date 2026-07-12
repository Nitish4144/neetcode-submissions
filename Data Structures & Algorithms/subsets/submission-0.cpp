class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> ans;
    void f(int ind,vector<int>& v, vector<int>& nums){
        if(ind == nums.size()) {
        if(s.insert(v).second) ans.push_back(v);
        return;
}
        v.push_back(nums[ind]);
        f(ind+1,v,nums);
        v.pop_back();
        f(ind+1,v,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        int ind =0;
        f(0,v,nums);
        return ans;
    }
};
