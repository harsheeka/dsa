class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1,index=1;
        while(i<nums.size()){
            if(nums[i]!=nums[i-1]){
                nums[index]=nums[i];
                index++,i++;
            }
            else{
                int v = nums[i];
                while(i<nums.size()&& v==nums[i]){
                    i++;
                }
            }
        }
        return index;
    }
};