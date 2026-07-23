class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans =0;
        ansS =""
        for i in range(len(s)):
            l,r =i,i
            while( l>=0 and r<len(s)):
                if(s[l] == s[r]):
                    if r-l+1 >ans: 
                        ans = r-l+1
                        ansS = s[l:r+1]
                    l-=1
                    r+=1
                else: break
            l,r=i,i+1
            while(l>=0 and r<len(s)):
                if(s[l] == s[r]):
                    if r-l+1 >ans: 
                        ans = r-l+1
                        ansS = s[l:r+1]
                    l-=1
                    r+=1
                else: break
        return ansS