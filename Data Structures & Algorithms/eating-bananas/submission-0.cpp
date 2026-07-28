class Solution {
public:
    bool f(int m, vector<int>& v, int h){
        int t = 0;
        for(int p:v){
            t+= (p/m +(p%m != 0));
        }
        return t <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l =1;
        // int r = 1000;
        int r = *max_element(piles.begin(), piles.end());
        int m = (l+r)/2;
        while(l<=r){
            if(f(m,piles,h)){
                r = m-1;
            }
            else l=m+1;
            m = (l+r)/2;
        }
        return l;
    }
};
