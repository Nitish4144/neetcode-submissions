class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> mp;
        unordered_map<string,bool> vis;
        int w = beginWord.size();
        bool f =false;

        for(auto& word:wordList){
            vis[word] = false;
            if( word == endWord) f = true;
            for(int j=0;j<w;j++){
                string s = word.substr(0,j)+"*"+word.substr(j+1,w-j-1);
                mp[s].push_back(word);
            }
        }
        if(!f) return 0;

        deque<string> q;
        q.push_back(beginWord);
        int ans =1;

        while(!q.empty()){
            ans+=1;
            int sz = q.size();
            for(int szi =0;szi<sz;szi++){
                string word = q.front();
                q.pop_front();
                for(int j=0;j<w;j++){
                    string s = word.substr(0,j)+"*"+word.substr(j+1,w-j-1);
                    bool k = true;
                    for(auto& wrd:mp[s]){
                        if(wrd != word and vis[wrd] == false){
                            // if(k) ans+=1,k=false;
                            if(wrd == endWord) return ans;
                            q.push_back(wrd);
                            vis[wrd]=true;
                        }
                    }
                }
            }
        }
        return 0;
    }
};
