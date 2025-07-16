class Solution {
public:
    bool isValid(string temp){
        for(int i=1;i<temp.size();i++){
            if(temp[i]-temp[i-1]!=1){
                return false;
            }
        }
        return true;
    }
    void res(vector<int> &result, int &low, int &high, string temp,int index){
        if(!temp.empty() && stoi(temp)>high){
            return;
        }
        else if(!temp.empty() && stoi(temp)>=low && isValid(temp)){
            result.push_back(stoi(temp));
        }
        for(int i = index; i<=9 ;i++){
            temp.push_back('0'+i);
            res(result,low,high,temp,i+1);
            temp.pop_back();
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        res(result,low,high,"",1);
         sort(result.begin(), result.end());
        return result;
    }
};