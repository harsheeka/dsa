class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size()==1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int i=0,j=1,cnt=0;
        while(j<nums.size()){
            int curr = nums[j] - nums[i];
            if(curr<k)j++;
            else if(curr>k){
                i++;
                if(i==j) j++;
            }
            else{
                cnt++;
                int v1 = nums[i],v2=nums[j];
                while(i<nums.size() && nums[i]==v1) i++;
                while(j<nums.size() && nums[j]==v2) j++;
                if(i==j)j++;
            }
        }
        return cnt;
    }
};