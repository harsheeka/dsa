class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1,index=1;
        while(i<nums.size()){
            if(nums[i]==nums[i-1]){
                nums[index]=nums[i];
                index++;
                int val = nums[i];
                while(i<nums.size()&& nums[i]==val){
                    i++;
                }
            }
            else{
                nums[index]=nums[i];
                index++;
                i++;
            }
        }
        return index;
    }
};