class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for(int i=0;i<numbers.size();i++){
            int l = i+1, h= numbers.size()-1, k = target - numbers[i];
            while(l<=h){
                int m = l + (h-l)/2;
                if(numbers[m]==k){
                    res.push_back(i+1);
                    res.push_back(m+1);
                    break;
                }
                else if(numbers[m]>k){
                     h=m-1;
                }
                else{
                    l=m+1;
                }
            }
        }
        return res;
    }
};