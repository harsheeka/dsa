class Solution {
public:
    void res(vector<string> &result,string temp, int &n, int len){
        if(temp.length()==n){
            result.push_back(temp);
            return;
        }
        if(temp[len-1]=='a'){
            res(result,temp+"b",n,len+1);
            res(result,temp+"c",n,len+1);
        }
        else if(temp[len-1]=='b'){
            res(result,temp+"a",n,len+1);
            res(result,temp+"c",n,len+1);
        }
        else if(temp[len-1]=='c'){
            res(result,temp+"a",n,len+1);
            res(result,temp+"b",n,len+1);
        }
    }
    string getHappyString(int n, int k) {
        vector<string> result;
        res(result,"a",n,1);
        res(result,"b",n,1);
        res(result,"c",n,1);
        if(k>result.size()) return "";
        return result[k-1];
    }
};