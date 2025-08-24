class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> vec(2);
       map<int,int> m;


       for(int i=0;i<nums.size();i++){
        if(m.find(nums[i])!=m.end()){
            m[nums[i]+1000000000]=i;
        }
        else m[nums[i]]=i;
       }
       
       for(int i=0;i<nums.size();i++){
        vec[0]=m[nums[i]];
        if(nums[i]*2 == target && m.find(nums[i]+1000000000)!= m.end()){
            vec[1]= m[nums[i]+1000000000];
            break;

        }
        else if(m.find(target-nums[i])!= m.end() && target-nums[i]!= nums[i]){
              vec[1]=m[target-nums[i]];
              break;
              }
       }
   

       return vec;
    }
};
