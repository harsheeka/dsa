class Solution {
public:
    bool isValid(string t){
        int n= t.length();
        for(int i=0;i<n/2;i++){
            if(t[i]!=t[n-i-1]) return false;
        }
        return true;
    }
    void res(vector<vector<string>> &result, vector<string> &temp, int index,string s){
        if(index==s.length()){
            result.push_back(temp);
            return;
        }
        for(int i=index;i<s.length();i++){
            string t = s.substr(index,i-index+1);
            if(!empty(t) && isValid(t)){
                temp.push_back(t);
                res(result,temp,i+1,s);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        res(result,temp,0,s);
        return result;
    }
};