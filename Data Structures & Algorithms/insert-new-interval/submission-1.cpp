class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inds, vector<int>& newinds) {
        int start = newinds[0];
        int end = newinds[1];
        int n =inds.size();
        vector<vector<int>> ans;
        int i =0;
        while(i<n and inds[i][1]< start){
            ans.push_back(inds[i++]);
        }
        while(i<n and inds[i][0]<=end){
            start = min(start,inds[i][0]);
            end = max(end,inds[i][1]);
            i+=1;
        }
        ans.push_back({start,end});
        while(i<n){
            ans.push_back(inds[i++]);
        }
        return ans;
    }
};
