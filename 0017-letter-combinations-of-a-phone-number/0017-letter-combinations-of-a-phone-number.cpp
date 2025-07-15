class Solution {
public:
    void comb(string &temp,int k, vector<string> &result, vector<vector<char>> &digitMap,string &digits){
        if(k==digits.length()){
            result.push_back(temp);
            return ;
        }
        for(int i=0;i<digitMap[digits[k]-'2'].size();i++){
            temp[k]= digitMap[digits[k]-'2'][i];
            comb(temp,k+1,result,digitMap,digits);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.length()==0){
            return result;
        }
        vector<vector<char>>digitMap;
        digitMap.push_back({'a','b','c'});
        digitMap.push_back({'d','e','f'});
        digitMap.push_back({'g','h','i'});
        digitMap.push_back({'j','k','l'});
        digitMap.push_back({'m','n','o'});
        digitMap.push_back({'p','q','r','s'});
        digitMap.push_back({'t','u','v'});
        digitMap.push_back({'w','x','y','z'});
        int k=0;
        string temp(digits.length(),' ');
        comb(temp,k,result, digitMap,digits);
        return result;

    }
};