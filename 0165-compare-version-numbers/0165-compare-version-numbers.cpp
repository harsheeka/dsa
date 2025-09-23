class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l = max(version1.length(),version2.length());
        int x=0,y=0;
        while(x<l && y<l){
            
            string s1 = x<version1.length() ? "" : "0";
            string s2 = y<version2.length() ? "" : "0";
            while(x<version1.length() && version1[x]!='.'){
                s1+=version1[x];
                x++;
            }
            x++;
            while(y<version2.length() && version2[y]!='.'){
                s2+=version2[y];
                y++;
            }
            y++;
            if(stoi(s1)>stoi(s2)){
                return 1;
            }
            else if(stoi(s2)>stoi(s1)){
                return -1;
            }
        }
        return 0;
    }
};