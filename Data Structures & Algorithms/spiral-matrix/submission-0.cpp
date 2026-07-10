class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<int> ans;
        vector<int> bound = {0, n - 1, m - 1, 0}; // top, right, bottom, left

        vector<pair<int, int>> dir = {
            {0, 1},   // right
            {1, 0},   // down
            {0, -1},  // left
            {-1, 0}   // up
        };

        int d = 0;
        int r = 0, c = 0;

        for (int cnt = 0; cnt < m * n; cnt++) {
            ans.push_back(matrix[r][c]);

            int nr = r + dir[d].first;
            int nc = c + dir[d].second;

            bool turn = false;

            if (d == 0 && nc > bound[1]) {          // right
                bound[0]++;
                turn = true;
            }
            else if (d == 1 && nr > bound[2]) {     // down
                bound[1]--;
                turn = true;
            }
            else if (d == 2 && nc < bound[3]) {     // left
                bound[2]--;
                turn = true;
            }
            else if (d == 3 && nr < bound[0]) {     // up
                bound[3]++;
                turn = true;
            }

            if (turn) {
                d = (d + 1) % 4;
                nr = r + dir[d].first;
                nc = c + dir[d].second;
            }

            r = nr;
            c = nc;
        }

        return ans;
    }
};