class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n =nums.size();
        int ans=0;
        for(int i =0;i<n;i++){
            mp[nums[i]]=1;
        }
        for(int i=0;i<n;i++){
            int ele = nums[i];
            int temp = ele;
            if(mp[ele] == 1){
                int a =1;
                while(mp.find(ele+1)!=mp.end() and mp[ele+1]>0)
                {
                    if( mp[ele+1]>1 ) {
                        mp[ele]=1+mp[ele+1];
                        a+=mp[ele+1];
                        break;
                    }
                    a+=1;
                    ele+=1;
                    // mp[ele].pop_back();
                }
                mp[temp]=a;
                ans=max(a,ans);
            }
            
            
        }
        return ans;
    }
};
