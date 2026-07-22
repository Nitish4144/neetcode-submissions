class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> hs(n,0);
        unordered_map<int,vector<int>> req;
        for(auto& it: prerequisites){
            req[it[1]].push_back(it[0]);
            hs[it[0]]+=1;
        }
        queue<int> q;
        vector<int> ans;
        for(int i =0;i<n;i++){
            if(hs[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int ele = q.front();
            q.pop();

            ans.push_back(ele);
            for(auto& crs:req[ele]){
                hs[crs]-=1;
                if(hs[crs] == 0) q.push(crs);
            }
        }
        if(ans.size() == n) return ans;
        else return {};
    }
};
