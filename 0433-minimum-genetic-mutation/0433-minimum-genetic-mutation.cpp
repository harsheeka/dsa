class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> genes(bank.begin(),bank.end());
        string letters = "ACGT";
        if(!genes.count(endGene)) return -1;
        map<string,bool> vis;
        queue<pair<string,int>> q;
        q.push({startGene,0});
        vis[startGene]=true;
        while(!q.empty()){
            pair<string,int> x = q.front();
            q.pop();
            string temp = x.first;
            for(int i=0;i<temp.length();i++){
                char ch = temp[i];
                for(int j=0;j<letters.length();j++){
                    char rep = letters[j];
                    temp[i]=rep;
                    if(genes.count(temp) && !vis[temp]){
                        if(temp==endGene){
                            return x.second+1;
                        }
                        vis[temp]=true;
                        q.push({temp,x.second+1});
                    }
                }
                temp[i]=ch;
            }
        }
        return -1;
    }
};