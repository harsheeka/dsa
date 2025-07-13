class Solution {
public:
    void out(vector<string>&result,int &n, string &temp, int l, int r, int i){
        if(i==(2*n)){
            result.push_back(temp);
            return;
        }
        if(l==r){
            temp[i]='(';
            out(result,n,temp,l+1,r,i+1);
        }
        else if(l>r){
            if(l==n){
                temp[i]=')';
                out(result,n,temp,l,r+1,i+1);
            }else{
                temp[i]=')';
                out(result,n,temp,l,r+1,i+1);
                temp[i]='(';
                out(result,n,temp,l+1,r,i+1);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp(2*n,' ');
        out(result,n,temp,0,0,0);
        return result;
    }
};