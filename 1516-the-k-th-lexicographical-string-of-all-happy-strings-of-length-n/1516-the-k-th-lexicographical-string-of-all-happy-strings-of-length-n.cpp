class Solution {
public:
    void res(vector<string> &result,string temp, int &n){
        if(temp.length()==n){
            result.push_back(temp);
            return;
        }
        for(char ch : {'a','b','c'}){
            if(temp.empty()|| temp.back()!=ch){
                res(result,temp+ch,n);
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string> result;
        res(result,"",n);
        if(k>result.size()) return "";
        return result[k-1];
    }
};