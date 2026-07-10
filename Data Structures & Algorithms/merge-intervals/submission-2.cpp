class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inds) {
    sort(inds.begin(), inds.end(),
        [](vector<int>& a,vector<int>& b) {
            return a[0] < b[0];
        });
        int start = inds[0][0];
        int end = inds[0][1];
        int i =1;
        int n = inds.size();
        bool f = false;
        vector<vector<int>> ans;
        if(n==1){
            return inds;
        }
        while(i<n){
            if(inds[i][0]<=end ) end = max(end,inds[i][1]),f=false;
            else {
                ans.push_back({start, end});
                start = inds[i][0];
                end = inds[i][1];
            }
            i++;
        }
        if(!f) ans.push_back({start,end});
        return ans;
    }
};
