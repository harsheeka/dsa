class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> word (wordList.begin(),wordList.end());
        map<string,bool> vis;
        queue <pair<string,int>> q;
        q.push({beginWord,1});
        vis[beginWord]=true;
        while(!q.empty()){
            pair<string,int> x = q.front();
            q.pop();
            string temp = x.first;
            for(int i=0;i<temp.size();i++){
                char ch = temp[i];
                for(int j=0;j<26;j++){
                    char rep = j + 'a';
                    temp[i]=rep;
                    if(word.count(temp) && !vis[temp]){
                        if(temp == endWord){
                            return x.second+1;
                }
                        vis[temp]=true;
                        q.push({temp,x.second+1});
                    }
                }
                temp[i]=ch;
            }
        }
        return 0;
    }
};