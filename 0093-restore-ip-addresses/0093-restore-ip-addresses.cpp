class Solution {
public:
    bool isValid(string t){
        if(t.length()>1 && t[0]=='0'){
            return false;
        }
        int val = stoi(t);
        if(val<0 || val>255){
            return false;
        }
        return true;
    }
    void res(vector<string>& result, string s, int seg, int i,string temp){
        if(i==s.length() && seg ==4){
            temp.pop_back();
            result.push_back(temp);
            return;
        }
        if(i==s.length() || seg==4){
            return;
        }
        for(int j=1;j<4;j++){
            if(j+i > s.length()) break;
            string t = s.substr(i,j);
            if(isValid(t)){
                res(result,s,seg+1,i+j,temp+t+'.');
            }
        }

    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        res(result,s,0,0,"");
        return result;
    }
};