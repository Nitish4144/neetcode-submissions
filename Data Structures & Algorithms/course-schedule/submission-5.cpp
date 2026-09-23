class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> v(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto it: prerequisites){
            indegree[it[0]]++;
            v[it[1]].push_back(it[0]);
        }
        queue<int> q;
        int finish = 0;
        for(int i =0;i<numCourses;i++){
            if(indegree[i] ==0) q.push(i);

        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            finish++;
            for(int nei:v[node]){
                indegree[nei]--;
                if(indegree[nei] == 0) q.push(nei);
            }

        }
        return ( finish == numCourses);
    }
};
