class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> curr(n,1);

        for(int r=m-2;r>=0;r--){
            for(int c=n-2;c>=0;c--){
                curr[c] = curr[c+1] + curr[c];
            }
        }
        return curr[0];
    }
};
