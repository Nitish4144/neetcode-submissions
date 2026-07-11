class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n =cost.size();
        // cost.push_back(0);
        if(n == 1) return cost[0];
        vector<int> c(n+1);
        c[0]=0;
        c[1]=0;
        for(int i=2;i<=n;i++){
            c[i] = min( c[i-1]+cost[i-1] ,c[i-2]+cost[i-2] );
        }
        return c[n];
    }
};
