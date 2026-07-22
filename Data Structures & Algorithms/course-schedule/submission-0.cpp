class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& prerequisites) {
        int n = num;
        vector<int> hs(n,0);
        unordered_map<int,vector<int>> req;
        for(auto& it: prerequisites){
            req[it[1]].push_back(it[0]);
            hs[it[0]]+=1;
        }
        queue<int> q;
        for(int i =0;i<n;i++){
            if(hs[i] == 0) q.push(i);
        }
        int ans = q.size();
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            for(auto& crs:req[ele]){
                hs[crs]-=1;
                if(hs[crs] == 0) q.push(crs),ans+=1;
            }
        }
        return (ans == n);
    }
};
