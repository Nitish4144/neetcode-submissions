class Solution {
public:
    void reverse(vector<vector<int>>& matrix, int& n){
        for(int row =0;row<n;row++){
            for(int col=0;col<row;col++) replace(matrix[row][col],matrix[col][row]);
        }
    }
    void reverseRow(vector<int>& v,int& n){
        for(int i=0;i<n/2;i++){
            replace(v[i],v[n-i-1]);
        }
        
    }
    void replace(int& a, int& b){
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        reverse(matrix,n);
        for(int row=0;row<n;row++){
            reverseRow(matrix[row],n);
        }
        // return matrix;
    }
};
