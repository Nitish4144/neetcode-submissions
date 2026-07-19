class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r = height.size()-1;
        int rM =height[r];
        int lM =height[l];
        l+=1;
        r-=1;
        int ans = 0;
        while(l<=r){
            if(height[l]>=lM){
                lM=max(height[l],lM);
                l++;
                continue;
            }
            if(height[r]>=rM){
                rM=max(height[r],rM);
                r--;
                continue;
            }

            if(
                // height[l]< min(lM,rM)
                lM<rM){
                ans+=min(lM,rM)-height[l];
                l++;
            }
            else 
            // if(
            //         // height[r]<min(lM,rM)
            //         rM
            //         )
                    {
                ans+=min(lM,rM)-height[r];
                r--;
            }
        }
        return ans;
    }
};
