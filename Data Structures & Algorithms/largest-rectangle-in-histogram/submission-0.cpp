class Solution {
public:
    vector<int> nextGreater(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, nums.size());
        stack<int> st; // stores indices

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            if (!st.empty())
                nge[i] = st.top();

            st.push(i);
        }

        return nge;
    }

    vector<int> prevGreater(vector<int>& nums) {
        int n = nums.size();
        vector<int> pge(n, -1);
        stack<int> st; // stores indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            if (!st.empty())
                pge[i] = st.top();

            st.push(i);
        }

        return pge;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nge = nextGreater(heights);
        vector<int> pge = prevGreater(heights);
        int ans =0;
        for(int i =0;i<heights.size();i++){
            ans = max(ans,(nge[i]-pge[i]-1)*heights[i]);
        }
        return ans;
    }
};
